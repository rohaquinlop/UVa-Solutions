'''
*
* Problema UVa 10025 - The ? 1 ? 2 ? ... ? n = k problem
*
'''

from sys import *
from math import *

def sumaRango(n):
	return int(n*(n+1)//2)

def main():
	cnt = 0
	out = ""
	lines = stdin.readlines()
	lines.pop(0)
	for line in lines:
		if line != "" and line != "\n":
			cnt += 1
			k = abs(int(line.strip()))
			if k >= 1:
				n = int(ceil((-1+sqrt(1+(8*k)))/2))
				while (sumaRango(n)-k)%2 != 0:
					n += 1
			else:
				n = 3

			if cnt > 1:
				out += "\n"
			out += str(n) + "\n"
	print(out.strip())

main()