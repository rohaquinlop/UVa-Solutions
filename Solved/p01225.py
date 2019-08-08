'''
*
* Problema UVa 1225 - Digit Counting
*
'''

from collections import Counter
from sys import *

n = int(stdin.readline())

while n > 0:
	n -= 1
	line = ""
	mNum = int(stdin.readline())

	for i in range(1, mNum+1):
		line += str(i)

	dNums = Counter(line)
	outLine = ""

	for i in range(0, 10):
		if( str(i) in dNums ):
			outLine += str(dNums[str(i)])
		else:
			outLine += "0"

		if( i < 9):
			outLine += " "

	print(outLine)