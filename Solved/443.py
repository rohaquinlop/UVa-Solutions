'''
*
* Problema UVa 443 - Humble Numbers
*
'''

from sys import *

nHumble = [0]*5842

def increaseIndex(a, b, c, d, nVal, a2, b3, c5, d7):
	if nVal == a2:
		a += 1
	if nVal == b3:
		b += 1
	if nVal == c5:
		c += 1
	if nVal == d7:
		d += 1
	return a, b, c, d

def min4(a, b, c, d):
	if (a <= b) and (a <= c) and (a <= d):
		return a
	elif (b <= a) and (b <= c) and (b <= d):
		return b
	elif (c <= a) and (c <= b) and (c <= d):
		return c
	elif (d <= a) and (d <= b) and (d <= c):
		return d

def humble():
	global nHumble
	nHumble[0] = 1
	i = 1
	i2 = 0
	i3 = 0
	i5 = 0
	i7 = 0

	while i < 5842:
		nVal = min4(nHumble[i2]*2, nHumble[i3]*3, nHumble[i5]*5, nHumble[i7]*7)
		i2, i3, i5, i7 = increaseIndex(i2, i3, i5, i7, nVal, nHumble[i2]*2, nHumble[i3]*3, nHumble[i5]*5, nHumble[i7]*7)
		nHumble[i] = nVal
		i += 1

def main():
	global nHumble
	out = ""
	lines = stdin.readlines()
	humble()
	for line in lines:
		n = int(line.strip())
		if( n == 0 ):
			break
		else:
			if n%10 == 1 and n%100 != 11:
				out += "The " + str(n) + "st humble number is " + str(nHumble[n-1]) + ".\n"
			elif n%10 == 2 and n%100 != 12:
				out += "The " + str(n) + "nd humble number is " + str(nHumble[n-1]) + ".\n"
			elif n%10 == 3 and n%100 != 13:
				out += "The " + str(n) + "rd humble number is " + str(nHumble[n-1]) + ".\n"
			else:
				out += "The " + str(n) + "th humble number is " + str(nHumble[n-1]) + ".\n"
	print(out.strip())

main()