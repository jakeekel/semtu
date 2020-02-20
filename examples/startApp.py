#! /usr/bin/python
import sys, time
from subprocess import Popen, PIPE

cmd = "./DataRace"

t_start = time.time()
numberOfExecutions = 10000
for i in range(0, numberOfExecutions):
	process = Popen(cmd, shell=True, stdout=PIPE, stderr=PIPE)
	out, err = process.communicate()
	print(out)

t_end = time.time()
t_exec = (t_end - t_start)/numberOfExecutions
print("Execution time = %s[s]" % t_exec) 
