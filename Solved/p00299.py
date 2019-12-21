'''
*
* Problema UVa 299 - Train Swapping
*
'''

from sys import *
##import time

def sort(lst):
	count = 0

	i = 0
	while i < len(lst)-1:
		a = lst[i]
		b = lst[i+1]
		if a > b:
			lst[i], lst[i+1] = lst[i+1], lst[i]
			i = 0
			count += 1
		else:
			i += 1
	return count

def main():
	lines = stdin.readlines()
	lines.pop(0)
	out = ""
	for i, line in enumerate(lines):
		if (i+1)%2 == 0: 
			count = 0
			line = line.strip().split()
			line = list(map(int, line))
			out += "Optimal train swapping takes {} swaps.\n".format(sort(line))
	print(out.strip())

##startTime = time.time()
main()
##print("--- %s seconds ---" % (time.time() - startTime))