from sys import stdin

def mic_wf(L,H,a):
  a.sort()
  ans,low,n,ok,N = list(),L,0,True,len(a)
  while ok and low<H and n!=N:
    ok = a[n][0]<=low
    best,n = n,n+1
    while ok and n!=N and a[n][0]<=low:
      if a[n][1]>a[best][1]:
        best = n
      n += 1
    ans.append(best)
    low = a[best][1]
  ok = ok and low>=H
  return ans if ok else list()

def main():
  lines = stdin.readlines()
  i = 0
  out = ""
  while i < len(lines):
    L, G = map(int, lines[i].strip().split())
    if L == 0 and G == 0:
      break
    else:
      i += 1
      stations = []
      for j in range(G):
        x, r = map(int, lines[i].strip().split())
        stations.append( [ max(0, x-r), min(L, x+r) ] )
        i += 1
    intervals = mic_wf(0, L, stations)
    if len(intervals) == 0:
      out += "-1\n"
    else:
      out += "{}\n".format(G-len(intervals))
  print(out.strip())

main()