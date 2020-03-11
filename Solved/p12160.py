'''
*
* Problema UVa 12160 - Unlock the Lock
*
'''
from collections import deque
from sys import stdin

def addStrings(s,t):
  res = str(int(s)+int(t))
  if len(res) >= 4:
    v = res[::-1]
    v = v[0:4]
    v = v[::-1]
    return v
  else:
    return res

# def addStrings(s, t):
#   res = ""
#   i = 3
#   carry = 0
#   while i >= 0:
#     v = int(s[i])+int(t[i])+carry
#     res += str(v%10)
#     carry = v//10
#     i -= 1
#   res = res[::-1]
#   return res


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
    L, U = l[0], l[1]
    i += 1
    rV = lines[i].strip().split()
    i += 1

    ## Do BFS since startNode to endNode taking endNode
    startNode, endNode = L, U
    q = deque()
    q.append([startNode, 0])
    found = False
    steps = 0
    memo = dict()
    memo[startNode] = 1

    while len(q) > 0:
      ## End and stop
      l = q.popleft()
      node = l[0]
      if node == endNode:
        steps = l[1]
        found = True
        break
      
      for r in rV:
        t = addStrings(node, r)
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