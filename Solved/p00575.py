'''
*
* Problema UVa 575 - Skew Binary
*
'''
import sys

def skewBinary(n):
    num = str(n)
    num = num[::-1]
    sum = 0
    for i in range(0, len(num)) :
        sum += int(num[i]) * (2**(i+1)-1)
    return sum

while(True):
    n = int( sys.stdin.readline() )
    if( n == 0 ):
        break
    else:
        print( "{0}".format( skewBinary(n)) )
