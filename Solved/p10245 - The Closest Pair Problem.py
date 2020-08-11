from sys import stdin
from math import sqrt

def pointsDistance(p, q):
  ## Return the points distance
  return sqrt( (p[0]-q[0])**2 + (p[1]-q[1])**2 )

def minVal(p, q):
  if p < q:
    return p
  else:
    return q

def minDistancePointSet(A, B, x, w):
  s = []
  i = len(A)-1

  while i >= 0:
    if( x-A[i][0] <= w ):
      s.append(A[i])
    else:
      break
    i -= 1
  
  i = 0
  while i < len(B):
    if( B[i][0]-x <= w ):
      s.append(B[i])
    else:
      break
    i += 1
  
  minDistance = 10000.0

  for i in range(len(s)-1):
    for j in range(i+1, len(s)):
      minDistance = minVal(minDistance, pointsDistance(s[i], s[j]))
  
  return minDistance

def aux(lst):
  ##Solving the problem

  if len(lst) == 1 or len(lst) == 0:
    return 10000.0
  elif len(lst) == 2:
    return pointsDistance(lst[0], lst[1])
  else:
    A = lst[0:len(lst)>>1] ##Lefft side
    B = lst[len(lst)>>1::] ##Right side

    d1 = aux(A)
    d2 = aux(B)
    d3 = minDistancePointSet(A, B, B[0][0], minVal(d1, d2))

    return minVal(d3, minVal(d1, d2))

def main():
  lines = stdin.readlines()
  i = 0
  out = ""
  while i < len(lines):
    points = []
    n = int(lines[i].strip())
    if n == 0:
      break
    else:
      i += 1
      for j in range(n):
        points.append( list(map(float, lines[i].strip().split()))  )
        i += 1
      
      points.sort(key=lambda x : (x[0], x[1]))
      ans = aux(points)

      if(ans < 10000):
        out += "{:.4f}".format(ans) + "\n"
      else:
        out += "INFINITY\n"
  print(out.strip())


main()