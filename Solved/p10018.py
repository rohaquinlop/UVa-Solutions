'''
*
* Problema UVA 10018 - Reverse and Add
*
'''
from sys import *

def revNum(n):
	rev = str(n)
	return int(rev[::-1])

def main():
	n = int(stdin.readline())

	for i in range(n):
		count = 1
		num = int(stdin.readline())
		num = num + revNum(num)
		rev = revNum(num)

		while num != rev:
			count += 1
			num = num+rev
			rev = revNum(num)

		print("{0} {1}".format(count, rev))



if __name__ == '__main__':
	main()