'''
*
* Problema UVA 10862 Connect the Cable Wires
*
'''

import sys

def createFibo():
	t1 = 0
	t2 = 1
	vec = []
	for i in range(8000):
		vec.append(t1)
		nextTerm = t1+t2
		t1 = t2
		t2 = nextTerm

	return vec

def main():
	fibos = createFibo()

	while True:
		n = int(sys.stdin.readline())
		if n == 0:
			break
		else:
			print("{0}".format(fibos[(2*n)]))


if __name__ == '__main__':
	main()