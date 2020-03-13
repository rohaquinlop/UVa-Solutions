'''
*
* Problema UVa 12160 - Unlock the Lock
*
'''
from collections import deque
from sys import stdin

def main():
  lines = stdin.readlines()
  i = 0
  c = 0
  out = ""
  while i < len(lines):
    c += 1
    l = lines[i].strip().split()
    if l[0] == '0' and l[1] == '0' and l[2] == '0':
      break
    L, U = int(l[0]), int(l[1])
    i += 1
    rV = list(map(int, lines[i].strip().split()))
    i += 1

    ## Do BFS since startNode to endNode taking endNode
    startNode, endNode = L, U
    q = []
    q.append([startNode, 0])
    found = False
    steps = 0
    memo = dict()
    memo[startNode] = 1
    j = 0

    while j < len(q):
      ## End and stop
      l = q[j]
      j += 1
      node = l[0]
      if node == endNode:
        steps = l[1]
        found = True
        break
      
      for r in rV:
        t = (node+r)%10000
        #q.append([t, l[1]+1])
        v = memo.get(t)
        if v == None:
          q.append([t, l[1]+1])
          memo[t] = 1
    
    if found:
      out += "Case " + str(c) + ": "  + str(steps) + "\n"
    else:
      out += "Case " + str(c) + ": Permanently Locked\n"
  
  print(out.strip())


main()