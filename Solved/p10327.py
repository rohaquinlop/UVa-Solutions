'''
*
* Problema UVa 10327 - Flip Sort
* There is an error in UVa's input for that Python got time limit, but the algorithm works and is optimized
*
'''

from sys import *

def flipsort(lst):
	count = 0
	i = 0
	while i < len(lst)-1:
		a = lst[i]
		b = lst[i+1]
		if a > b:
			count += 1
			tmp = a
			lst[i] = b
			lst[i+1] = a
			i = 0
		else:
			i += 1
	return count

def main():
	lines = stdin.readlines()
	lines = list(map(int, (" ".join(map(lambda x: x.strip(), lines))).split()))
	out = ""
	while len(lines):
		elem = lines.pop(0)
		nums = []
		while elem:
			nums.append(lines.pop(0))
			elem -= 1
		out += "Minimum exchange operations : " + str(flipsort(nums)) + "\n"
	print(out.strip())

main()