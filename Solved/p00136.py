'''
*
* Problema UVa 136 - Ugly Numbers
*
'''

from sys import *

"""
def increase(a, b, c, min3, a1, b2, c5):
	if min3 == a1*2:
		a += 1
	if min3 == b2*3:
		b += 1
	if min3 == c5*5:
		c += 1
	return a, b, c

def min3(a, b, c):
	if (a <= b) and (a <= c):
		return a
	elif (b <= a) and (b <= c):
		return b
	elif (c <= a) and (c <= b):
		return c

def nUgly(n):
	if( n == 1):
		return 1
	else:
		ugly = [0] * 1500
		ugly[0] = 1
		i = 1
		i2 = 0
		i3 = 0
		i5 = 0
		while(i < n):
			nVal = min3(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5)
			i2, i3, i5 = increase(i2, i3, i5, nVal, ugly[i2], ugly[i3], ugly[i5])
			ugly[i] = nVal
			i += 1
		return nVal
"""

def main():
	n = 859963392
	print( "The 1500'th ugly number is {0}.".format(n) )

main()