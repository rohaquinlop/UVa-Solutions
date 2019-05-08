'''
*
* Problema UVA 11764 - Jumping Mario
*
'''
import sys

cases = int(sys.stdin.readline())
c = 0

for i in range(cases):
	c += 1
	nWalls = int(sys.stdin.readline())
	array = sys.stdin.readline().strip().split(' ')
	high = 0
	low = 0

	for j in range(len(array)-1):
		if( int(array[j]) < int(array[j+1]) ):
			high += 1
		elif( int(array[j]) > int(array[j+1]) ):
			low += 1

	print("Case {0}: {1} {2}".format(c, high, low))