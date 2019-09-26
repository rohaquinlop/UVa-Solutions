'''
*
* Problema UVa 374 - Big Mod
*
'''
import sys, math

def expBin(b, p, m):
	if( p == 0 ):
		return 1
	else:
		if( p%2 == 0 ):
			c = (expBin(b,p//2,m))%m
			return (c*c)%m
		else:
			return (b*expBin(b, p-1, m))%m

lines = sys.stdin.readlines()
i = 0
out = ""
while i < len(lines):
	b = int(lines[i].strip())
	p = int(lines[i+1].strip())
	m = int(lines[i+2].strip())
	i += 4
	out += str(int(expBin(b, p, m))) + "\n"

print(out.strip())