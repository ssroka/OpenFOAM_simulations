#read file
with open("0/cellDist", "r") as cdFile:
    lines = cdFile.readlines()

#replace and delete unwanted lines
lines[11] = lines[11].replace("volScalarField", "labelList")
lines[12] = lines[12].replace("0", "constant")
del lines[17:21]
bfline = 0
for i, line in enumerate(lines):
    if (line.find("boundaryField") != -1):
        bfline = i
        break
del lines[i:]

#write file
with open("constant/cellDist", "w") as cdFile:
    for line in lines:
        cdFile.write(line)