'''
*
* Problema UVa 787 - Maximum Sub-sequence Product
*
'''
import sys

nums = []

while True:
	nums = sys.stdin.readline().strip().split(' ')
	if( len(nums) == 1 ):
		break
	else:
		high = int(nums[0])
		for i in range(0, len(nums)-1):
			acum = 1
			for j in range(i, len(nums)-1):
				acum = acum * int(nums[j])
				if( acum > high ):
					high = acum


		print("{0}".format( int(high) ))