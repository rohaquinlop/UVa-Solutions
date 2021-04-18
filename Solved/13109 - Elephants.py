from sys import stdin

def main():
  lines = stdin.readlines()
  i = 1
  n = int( lines[0].strip() )
  out = ""
  while n > 0:
    n -= 1
    A = list(map(int, lines[i].strip().split()))
    i += 1
    B = list(map(int, lines[i].strip().split()))
    i += 1

    B.sort()
    web = A[1]
    cnt = 0
    for b in B:
      if b <= web:
        cnt += 1
        web -= b
      else:
        break
    out += "{}\n".format(cnt)
  print(out.strip())

main()