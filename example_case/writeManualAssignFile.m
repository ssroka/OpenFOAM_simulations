% region names

names = {
    'lowest'
    'lower 1'
    'lower 2'
    'middle 1'
    'middle 2'
    'middle 3'
    'middle 4'
    'middle 5'
    'middle 6'
    'middle 7'
    'middle 8'
    'middle 9'
    'middle 10'
    'upper 1'
    'upper 2'
    'highest'
    };

bnds = {
    '$z0'
    '$Lz'
    };

nCores = 16;
int_lvls = cell(nCores,1);
h = [-1.0 -0.45 -0.25 -0.05:0.01:0.05 0.25 0.45 1.0];

%%

int_lvls{1} = bnds{1};
int_lvls{nCores+1} = bnds{2};

for i = 2:nCores
    int_lvls{i} = sprintf('$z%d',i-1);
end

%%

fid = fopen('system/int_lvls','w');
for i = 1:length(h)
fprintf(fid,'%s %f;\n',int_lvls{i}(2:end),h(i));% rm $ from z name
end
fclose(fid);

%%

fid = fopen('system/manualAssign','w');
for i = 1:length(names)
    fprintf(fid,'// %s id = %d\n',names{i},i);
    fprintf(fid,'boxToCell\n{\n');
    fprintf(fid,'     box ($x0 $y0 %s) ($Lx $Ly %s);\n',int_lvls{i},int_lvls{i+1});
    fprintf(fid,'     fieldValues\n     (\n');
    fprintf(fid,'          volScalarFieldValue cellDist %d\n',i-1);% zero indexed
    fprintf(fid,'     );\n}\n');
end
fclose(fid);
