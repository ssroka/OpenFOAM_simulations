


This case corresponds to the 'fine' grid spacing and 140 kg /s^-1 /m^2 from

Sroka, S. (2021) "Sea Spray-Mediated Fluxes at Extreme Wind Speeds" (Doctoral
dissertation) Department of Mechanical Engineering, Massachusetts Institute of Technology

available at dspace.mit.edu



General Overview:
The version of OpenFOAM used is v1806. The solver is a modified version of
icoReactingMultiphaseInterFoam (see zip file
my_icoReactingMultiphaseInterFoam.zip)


Issues with parallel simulations--------
The doubly periodic boundary conditions in the horizontal appeared to require
that the cells which were on the boundary needed to be on the same core. A bug
report was made, but to accomidate this some helper files were created. 

When modifying the grid, always initialize Blockmesh with the final number of
z levels. Edit int_lvls and manualAssign as needed. Edit decomposePar to have
the desired number of cores, but leave everthing else. Run PrepManualDecomp.

system/int_lvls- defines all of the vertical levels of the grid (this was
generated programatically)
system/manualAssign- this works with the setFields call in prepDecomp.py which
is a step inside PrepManualDecomp.


Directional refinement steps are called from Allrun.


getSaveTimes.py

Writes out the timestamps of when the results files were saved. Be sure to
edit the year. 

getTimesteps.py

Writes out the timesetp and the corresponding point in simulation time. Ensure
that the range of values in f_num exceeds your total time.


Reconstruct

use this to reconstruct the parallel case and also to write the cell volumnes
and centers. 
