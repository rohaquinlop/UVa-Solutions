'''
*
*
* Problema UVa 10341 - Solve It
*
*
'''

from math import *
from sys import stdin

epsilon = 0.0000000001

def f(p, q, r, s, t, u, x):
  return p*exp(-1*x)+q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u

def main():
  lines = stdin.readlines()
  out = ""
  for case in lines:
    case = list(map(int, case.strip().split() ))
    lo, hi = 0, 1
    xi = f(case[0], case[1], case[2], case[3], case[4], case[5], lo)
    xu = f(case[0], case[1], case[2], case[3], case[4], case[5], hi)

    if( xi*xu > 0 ):
      out += "No solution\n"
    else:
      while lo+epsilon < hi:
        mid = (lo+hi)/2
        valXi = f(case[0], case[1], case[2], case[3], case[4], case[5], lo)
        valXr = f(case[0], case[1], case[2], case[3], case[4], case[5], mid)
        if valXi*valXr <= 0:
          hi = mid
        else:
          lo = mid
      out += str( "{0:.4f}\n".format((lo+mid)/2) )
  print(out.strip())

main()