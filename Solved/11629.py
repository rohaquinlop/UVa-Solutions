'''
*
* Problema 11629 - Ballot evaluation
*
'''
from sys import stdin

def main():
	line = stdin.readline()
	p, g = map(int, line.strip().split())
	d = dict()

	for i in range(p):
		line = stdin.readline().strip().split()
		palabra = line[0]
		numeroFlotante = line[1]

		aux = float(numeroFlotante)

		a = int(aux)
		b = (aux - a)*10

		d[palabra] = a*10+b

	for i in range(g):
		line = stdin.readline().strip().split()

		accum = 0

		for j in range(len(line)-1):
			if line[j] == "<":
				n = int(line[j+1])*10

				if accum < n:
					print("Guess #{} was correct.".format(i+1))
				else:
					print("Guess #{} was incorrect.".format(i+1))
			elif line[j] == ">":
				n = int(line[j+1])*10

				if accum > n:
					print("Guess #{} was correct.".format(i+1))
				else:
					print("Guess #{} was incorrect.".format(i+1))
			elif line[j] == "<=":
				n = int(line[j+1])*10

				if accum <= n:
					print("Guess #{} was correct.".format(i+1))
				else:
					print("Guess #{} was incorrect.".format(i+1))
			elif line[j] == ">=":
				n = int(line[j+1])*10

				if accum >= n:
					print("Guess #{} was correct.".format(i+1))
				else:
					print("Guess #{} was incorrect.".format(i+1))
			elif line[j] == "=":
				n = int(line[j+1])*10

				if accum == n:
					print("Guess #{} was correct.".format(i+1))
				else:
					print("Guess #{} was incorrect.".format(i+1))
			elif line[j] != "+":
				accum = accum + d[line[j]]
main()