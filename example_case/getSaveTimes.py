
import calendar
import os
from datetime import datetime


os.system("ls -lt processor0 > savetimes.txt")

d = {month: index for index, month in enumerate(calendar.month_abbr) if month}

fout = open('savetimes_delta.txt','w')

f = open("savetimes.txt",'r')
t_prev = None
lines = f.readlines()
for line in lines:
	if (line[0:3]=="drw") and (line[-3:]!="VTK") and (line[-8:]!="constant"):
		minute = ' '.join(line.split())
		dt_extract = "2021 "+' '.join(line.split()[5:8])
		line_timestamp = datetime.strptime(dt_extract,"%Y %b %d %H:%M")
		if t_prev is not None:
			dt = t_prev - line_timestamp
			fout.write("%s %s\n" % (dt.total_seconds(),step_prev))
		t_prev = line_timestamp
		step_prev = line.split()[8]
f.close()

fout.close()


