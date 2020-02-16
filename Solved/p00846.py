'''
*
* Problema UVa 846 - Steps
*
'''
from math import ceil
from sys import stdin, stdout

def cantSteps(lo, hi):
  j = 0
  move = 0
  increments = 1

  while lo < hi:
    j += 1
    if move == 0:
      lo += increments
      move = 1
    else:
      hi -= increments
      increments += 1
      move = 0
  
  return j

  return j

def main():
  lines = stdin.readlines()
  i = 1
  while i < len(lines):
    case = list(map(int, lines[i].strip().split()))
    x, y = case[0], case[1]
    stdout.write( str(cantSteps(x, y))+"\n" )
    i += 1

main()