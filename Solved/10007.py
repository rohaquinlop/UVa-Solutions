def fact(n):
	if n == 1:
		return 1
	else:
		return n * fact(n-1)

while True:
	try:
		n = int(input())
		if n == 0:
			break
		else:
			res = fact(2*n)//( fact(n)*(n+1) )
			print("{0}".format(int(res)))
	except:
		break