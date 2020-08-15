from sys import stdin
from math import sqrt, cos, radians

epsilon = 1e-10

def getT(theta, x):
  return cos(radians(theta))*x

def getVal(x, t):
  return sqrt(x**2-t**2)

def harmonicMean(m, n):
  return ((1/m)+(1/n))

def minVal(x, y):
  if x < y:
    return x
  else:
    return y

def binSearch(x, y, c):
  low = 0.0
  hi = 90.0
  mid = (low+hi)/2
  m = 0.001
  n = 0.001
  i = 0
  while abs(harmonicMean(m, n)-(1/c) )  > epsilon and i < 26:
    mid = (low+hi)/2
    t = getT(mid, x)
    i += 1
    if t < minVal(x, y):
      m = getVal(x, t)
      n = getVal(y, t)
      if harmonicMean(m, n) < (1/c):
        hi = mid
      else:
        low = mid
    else:
      low = mid
  return getT(mid, x)

def main():
  lines = stdin.readlines()
  out = ""
  for line in lines:
    line = list(map(float, line.strip().split()))
    x, y, c = line[0], line[1], line[2]
    out += "{:.3f}\n".format(binSearch(x, y, c))
  print(out.strip())

main()