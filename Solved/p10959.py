'''
*
* Problema UVa 10959 - The Party, Part I
*
'''

from sys import stdin

def main():
  cases = int(stdin.readline().strip())
  out = ""
  c = cases
  while cases>0:
    cases -= 1
    l = stdin.readline()
    l = list(map(int, stdin.readline().strip().split()))
    p, d = l[0], l[1]
    graph = [ [] for i in range(p) ]
    visited = [0 for i in range(p)]
    danceValue = [0 for i in range(p)]

    for i in range(d):
      l = list(map(int, stdin.readline().strip().split()))
      a, b = l[0], l[1]
      graph[a].append(b)
      graph[b].append(a)
    
    ##Queue
    queue = []
    queue.append(0)
    visited[0] = 1
    i = 0
    while i < len(queue):
      act = queue[i]
      i += 1
      tam = len(graph[act])
      for j in range(tam):
        node = graph[act][j]
        if not(visited[node]):
          queue.append(node)
          danceValue[node] = danceValue[act]+1
          visited[node] = 1
    
    if cases < c:
      out += "\n"

    for v in range(1, p):
      out += str(danceValue[v]) + "\n"
  
  print(out.strip())


main()