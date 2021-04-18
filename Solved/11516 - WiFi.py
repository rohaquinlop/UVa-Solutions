from sys import stdin

eps = 1e-7

def canGetCovered(housePos, n, diameter):
  ##Function that determine if all the houses can be covered given a diameter
  cnt = 1
  dist = housePos[0]+diameter
  for i in range(len(housePos)):
    if housePos[i] > dist:
      cnt += 1
      dist = housePos[i]+diameter
    if cnt > n:
      return False
  return True

def getDiameter(housePos, n, m):
  ##Function that determines de minimum diameter needed to cover all the houses
  lo, hi = 0, housePos[m-1]

  while abs(hi-lo) > eps:
    mid = (hi+lo)/2
    if canGetCovered(housePos, n, mid): hi = mid
    else: lo = mid
  return lo

def main():
  lines = stdin.readlines()
  i = 1
  out = ""
  while i < len(lines):
    housePos = []
    n, m = map(int, lines[i].strip().split())
    i += 1
    for j in range(m):
      housePos.append(int(lines[i].strip()))
      i += 1
    if n >= m or m < 2:
      ##Every house can have at least one access point
      out += "0.0\n"
    else:
      housePos.sort()
      diameter = getDiameter(housePos, n, m)
      radious = diameter/2
      out += "{:.1f}\n".format(radious)
  print(out.strip())

main()