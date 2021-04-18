import sys

while True:
	try:
		n = int(sys.stdin.readline())
		found = False
		x = 0
		accum = 1

		while not found:
			x += 1
			if( accum%n == 0 ):
				found = True
			else:
				accum = (accum*10)+1
		print(x)
	except:
		break