from sys import stdin
from math import *

EPS =  1e-9

def getS(theta, r):
  return 2*radians(theta)*r

def getR(theta, l):
  return l/(2*sin(radians(theta)))

def binSearch(l, s):
  low = 0.0
  hi = 90.0
  mid = (low+hi)/2
  r = getR(mid, l)
  sPrima = getS(mid, r)
  cnt = 1
  while (abs(s-sPrima) > EPS) and (cnt < 50):
    cnt += 1
    mid = (low+hi)/2
    r = getR(mid, l)
    sPrima = getS(mid, r)
    if sPrima < s:
      low = mid
    else:
      hi = mid
  ans = 0
  c1 = sqrt(r**2-(l/2)**2)
  ans = r-c1
  return ans

def main():
  lines = stdin.readlines()
  out = ""
  for line in lines:
    line = list(map(float, line.strip().split()))
    l, n, c = line[0], line[1], line[2]
    if l < 0 and n < 0 and c < 0:
      break
    else:
      s = l*(1+n*c)
      out += "{:.3f}\n".format(binSearch(l, s))
  print(out.strip())



main()