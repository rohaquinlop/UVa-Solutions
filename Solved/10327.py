'''
*
*
* Problema UVa 10327 - Flip Sort
*
*
'''
from sys import stdin, stdout

count = 0

## Merge Sort
def concatenate(a, b):
	"""
	Funcion que recibe dos listas y las concatena respetando el orden de cada elemento
	"""
	global count
	res = []
	i = 0
	j = 0
	while (i < len(a)) or ( j < len(b)):
		if i == len(a):
			res.append(b[j])
			j += 1
		elif j == len(b):
			res.append(a[i])
			i += 1
		else:
			if a[i] <= b[j]:
				res.append(a[i])
				i += 1
			else:
				res.append(b[j])
				count += len(a)-i
				j += 1
	return res

def divideLst(lst):
	res = []
	mid = len(lst)//2
	i = 0
	while i < mid:
		res.append(lst[i])
		i += 1
	return res, lst[i::]

def mergeSort(lst):
	if len(lst) == 1:
		return lst
	else:
		a, b = divideLst(lst)
		return concatenate( mergeSort(a), mergeSort(b) )

"""
def main():
	global count
	lines = stdin.readlines()
	lines = list(map(int, (" ".join(map(lambda x: x.strip(), lines))).split()))
	out = ""
	while len(lines):
		count = 0
		elem = lines.pop(0)
		nums = []
		while elem:
			nums.append(lines.pop(0))
			elem -= 1
		nums = mergeSort(nums)
		out += "Minimum exchange operations : " + str(count) + "\n"
	stdout.write(out)
"""
"""
def main():
	global count
	out = ""
	while True:
		n = stdin.readline()
		if len(n) != 0:
			count = 0
			n = int(n)
			nums = [ int(x) for x in stdin.readline().split() ]
			nums = mergeSort(nums)
			out += "Minimum exchange operations : "  + str(count) + "\n"
		else:
			stdout.write(out)
			break
"""

def main():
  global count
  lines = stdin.readlines()
  lines = list(map(int, (" ".join(map(lambda x: x.strip(), lines))).split()))
  i = 0
  while i < len(lines):
    count = 0
    elem = lines[i]
    nums = []
    i += 1
    j = 0
    while j < elem:
      nums.append(lines[i])
      i += 1
      j += 1
    nums = mergeSort(nums)
    stdout.write("Minimum exchange operations : " + str(count) + "\n")

main()