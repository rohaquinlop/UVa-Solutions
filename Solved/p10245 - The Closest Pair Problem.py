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

def minDistancePointSet(A, B, mid, d):
  s = []
  i = len(A)-1

  while i >= 0:
    if(mid-A[i][0] <= d):
      s.append(A[i])
    else:
      break
    i -= 1
  
  i = 0
  while i < len(B):
    if( B[i][0]-mid <= d ):
      s.append(B[i])
    else:
      break
    i += 1
  
  minDistance = 10000.0
  s.sort(key= lambda e : e[1])
  for i in range(len(s)-1):
    minDistance = minVal( minDistance, pointsDistance(s[i], s[i+1]))
  return minDistance

def aux(lst):
  ##Solving the problem

  if len(lst) <= 3:
    ## Brute Force 3^2 = 9 | No problem
    res = 10000.0
    for i in range(len(lst)-1):
      for j in range(i+1, len(lst)):
        res = minVal(res, pointsDistance(lst[i], lst[j]))
    return res
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