from sys import stdin
from math import floor
"""
eps = 1e-13

def cantor(n, lo, hi):
  if( abs(lo-n) < eps ):
    return True
  elif( abs(n-hi) < eps ):
    return True
  elif( abs(lo-hi) < eps ):
    return False
  else:
    cutPoint = (hi-lo)/3

    if( lo <= n <= lo+cutPoint ):
      return cantor(n, lo, lo+cutPoint)
    elif( hi-cutPoint <= n <= hi ):
      return cantor(n, hi-cutPoint, hi)
    else:
      return False
"""

def cantor(num):
  memo = dict()
  flag = True

  while flag:
    if memo.get(num) != None:
      break
    else:
      memo[num] = 1
      num = num*3.0
      i = int(num)
      if i == 1:
        flag = False
        break
      else:
        num = round(num-int(num), 6)
  return flag


def main():
  lines = stdin.readlines()
  out = ""
  for line in lines:
    line = line.strip()
    if line == 'END':
      break
    else:
      num = float(line)
      if num == 1.0 or num == 0.0:
        out += "MEMBER\n"
      else:
        if cantor(num):
          out += "MEMBER\n"
        else:
          out += "NON-MEMBER\n"
  print(out.strip())


main()