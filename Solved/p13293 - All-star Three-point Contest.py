from sys import stdin

def countPoints(points):
  ans = 0
  for p in points:
    p = [int(num) for num in p.split()]
    for i in range(len(p)):
      if i == len(p)-1:
        ans += 2*p[i]
      else:
        ans += p[i]
  return ans

def getUser(lst):
  name = lst[0]
  points = countPoints(lst[1:])
  return [name, points]

def main():
  lines = stdin.readlines()
  i = 0
  c = 0
  out = ""
  while i < len(lines):
    c += 1
    n = int(lines[i].strip())
    scores = []
    for j in range(n):
      i += 1
      scores.append( getUser(lines[i].strip().split(';')) )
    i += 1
    scores.sort(key = lambda x : (-x[1], x[0].lower()))
    out += "Case {0}:\n".format(c)
    for score in scores:
      out += "{} {}\n".format(score[0], score[1])
  print(out.strip())


main()