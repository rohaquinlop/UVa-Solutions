'''
*
* Problema UVa 424 - Integer Inquiry
*
'''
import sys

c = 0

while(True):
    n = int( sys.stdin.readline() )
    if( n == 0 ):
        break
    else:
        c += n

print( "{0}".format(c)  )
