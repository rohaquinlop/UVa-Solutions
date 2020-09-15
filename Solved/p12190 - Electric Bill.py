from sys import stdin

def money(n):
  i, res, a = 0, 0, 0
  while n > 0:
    if i == 0:
      a = min(n, 100)
      res += a*2
      n -= a
    elif i == 1:
      a = min(n, 9900)
      res += a*3
      n -= a
    elif i == 2:
      a = min(n, 990000)
      res += a*5
      n -= a
    elif i == 3:
      res += n*7
      n = 0
    i += 1
  return res

def consumption(n):
  i, res, a = 0, 0, 0
  while n > 0:
    if i == 0:
      a = min(n, 200)
      res += a//2
      n -= a
    elif i == 1:
      a = min(n, 29700)
      res += a//3
      n -= a
    elif i == 2:
      a = min(n, 4950000)
      res += a//5
      n -= a
    elif i == 3:
      res += n//7
      n = 0
    i += 1
  return res


def binSearch(A, B):
  lo, hi = 0, consumption(A)
  totalConsumption = consumption(A)
  while lo+1 < hi:
    mid = lo + ((hi-lo)>>1)
    actDiff = money(totalConsumption-mid)-money(mid)
    if actDiff <= B:
      hi = mid
    else:
      lo = mid
  return hi

def main():
  lines = stdin.readlines()
  out = ""
  for line in lines:
    line = list(map(int, line.strip().split()))
    A, B = line[0], line[1]
    if A == 0 and B == 0:
      break
    out += str(money(binSearch(A, B))) + "\n"
  print(out.strip())

main()