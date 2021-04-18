'''
*
*
* Problema UVa 12640 - Largest Sum Game
*
*
'''
from sys import *

lines = stdin.readlines()
res = ""

for line in lines:
  line = list(map(int, line.strip().split()))
  accum = 0
  maxVal = 0
  for num in line:
    maxVal = max(maxVal, max(accum, max(accum+num, num)))
    if accum + num < 0:
      ##
      accum = 0
    else:
      accum += num
  res += str(maxVal) + "\n"

print(res.strip())