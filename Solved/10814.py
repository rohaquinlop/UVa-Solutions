'''
*
* Problema UVA 10814 - Simplifying Fractions
*
'''

import sys

def gcd(a, b):
	while(b):
		a, b = b, a%b

	return a

def main():
	cases = int( sys.stdin.readline().strip() )

	while cases > 0:
		line = sys.stdin.readline().strip()
		line = line.split()
		a = int(line[0])
		b = int(line[2])

		print( "{} / {}".format( a// gcd(a,b), b// gcd(a,b) ) )

		cases -= 1

if __name__ == '__main__':
	main()