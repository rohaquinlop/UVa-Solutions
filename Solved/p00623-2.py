import sys, math

lines = sys.stdin.readlines()
output = ""

for line in lines:
	line = int(line.strip())
	output += str(line)+"!"+"\n"+str(math.factorial(line))+"\n"

print(output.strip())