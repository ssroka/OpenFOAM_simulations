#!/bin/bash/python3

import sys
from pathlib import Path
f_num = [float(x/1000) for x in list(range(0,3381,5))]
fout = open('timesteps.txt','w')

for i in f_num[1:]:
	if Path("processor0/{:g}/uniform/time".format(i)).is_file():
		f = open("processor0/{:g}/uniform/time".format(i),'r')
		lines = f.readlines()
		for line in lines:
			if (line[0:5]=="index"):
				fout.write("{:g}, {}\n".format(i, line.split("index")[1].split(";")[0].strip()))
		f.close()

fout.close()

