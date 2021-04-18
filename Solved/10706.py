"""
*
* Problema 10706 - Number Sequence
*
"""

from sys import stdin, setrecursionlimit

def solve(i, S, num):
  S = "1"
  num = 1
  while i > len(S):
    i -= len(S)
    num += 1
    S += str(num)
  return S[i-1]

def main():
  t = int(stdin.readline())
  out = ""

  while t > 0:
    t -= 1
    i = int(stdin.readline())

    out += "{}\n".format(solve(i,"1", 1))
  
  print(out, end="")

main()
