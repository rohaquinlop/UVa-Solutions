'''
*
* Problema UVA 10579 - Fibonacci Numbers
*
'''

import sys

def createFibo():
	t1 = 0
	t2 = 1
	vec = []
	for i in range(0, 8001):
		vec.append(t1)
		nextTerm = t1+t2
		t1 = t2
		t2 = nextTerm

	return vec

def main():

	fibos = createFibo()

	while True:
		try:
			n = int(input())
			print(fibos[n])
		except :
			break

if __name__ == '__main__':
	main()
