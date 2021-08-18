#!/bin/bash
#


# Job 
#SBATCH --job-name=runVTK
# 

# Partition             Nodes   S-C-T   Timelimit
# ---------             -----   -----   ---------
# sched_mit_hill        (32)    2-8-1   12:00:00
# sched_any_quicktest   2       2-8-1   00:15:00
# newnodes              (32)    2-10-1  12:00:00
#
#SBATCH --partition=sched_mit_twcronin
# #SBATCH --partition=newnodes
# #SBATCH --mem-per-cpu=50
#SBATCH --constraint=centos7
#SBATCH --time=12:00:00
#SBATCH --tasks-per-node=1
#SBATCH --nodes=1

# Streams
#SBATCH -o "runVTK_%j.out"
#SBATCH -e "runVTK_%j.err"

# Modules
module add engaging/openmpi/1.8.8
module add engaging/OpenFOAM/4.0

# Modules
cd ~/pkg
. ./of_startup.sh

rundir='example_case'
runfile='runVTK'
# printenv | sort
cd OpenFOAM/Cases/$rundir
str="$rundir $SLURM_JOB_ID $1 getVTKs of $rundir $SLURM_JOB_ID $1"
echo $str >> logfile_example_case.txt




# Content
# reconstructPar -latestTime
# foamToVTK -latestTime
reconstructPar
foamToVTK





