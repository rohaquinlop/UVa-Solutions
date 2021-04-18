'''
*
* Problema UVa 623 - 500!
*
'''
import math
import sys

while True:
	try:
		n = int(input())

		print("{0}!\n{1}".format(n, math.factorial(n)))
	except:
		break