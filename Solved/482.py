'''
*
*
* Problema UVA 482 - Permutation Arrays
*
*
'''
import sys

n = int(sys.stdin.readline())
c = 0

for i in range(n):
	c+=1
	if(c > 1):
		print()

	space = sys.stdin.readline()
	line1 = sys.stdin.readline().strip().split(' ')
	line2 = sys.stdin.readline().strip().split(' ')

	for j in range(len(line1)):
		count = 0
		for k in line1:
			count += 1
			if j == int(k)-1:
				print(line2[count-1])
