'''
*
* Problema UVa 113 - Power of Cryptography
*
'''
from math import *

while(True):
    try:
        n = int( input() )
        p = int( input() )
        num = p ** ( 1.0/n )
        if( num - int(num) > 0.5 ):
            print( int(ceil(num))  )
        else:
            print( int(num)  )
    except:
        break
