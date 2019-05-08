'''
*
* Problema UVA 495 Fibonacci Freeze
*
'''
import sys

def createFib():
	vec = []
	t1 = 0
	t2 = 1

	for i in range(5001):
		vec.append(t1)
		aux = t1+t2
		t1 = t2
		t2 = aux

	return vec

def main():
	fibos = createFib()

	while True:
		try:
			n = int(input())
			print( "The Fibonacci number for {0} is {1}".format(n, fibos[n]) )
		except:
			break


if __name__ == '__main__':
	main()