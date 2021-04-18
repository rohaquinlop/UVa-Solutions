"""
*
* Problema 11518 - Dominos 2
*
"""
from sys import stdin
from collections import deque

def main():
  cases = int(stdin.readline())
  out = ""

  while cases != 0:
    cases -= 1
    n, m, l = map(int, stdin.readline().strip().split())

    graph = [ [] for _ in range(n) ]
    visited = [False for _ in range(n)]

    for _ in range(m):
      x, y = map(int, stdin.readline().strip().split())
      graph[x-1].append(y-1)

    t = 0
    for _ in range(l):
      z = int(stdin.readline().strip())-1

      if visited[z] == False:       
        cola = deque()
        cola.append(z)
        visited[z] = True

        while cola:
          t += 1
          front = cola.popleft()

          for j in graph[front]:
            if visited[j] == False:
              visited[j] = True
              cola.append(j)
    
    out += "{}\n".format(t)
  
  print(out, end="")


main()