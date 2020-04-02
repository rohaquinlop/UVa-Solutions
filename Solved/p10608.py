'''
*
* Problema UVa 10608 - Friends
*
'''
from sys import stdin

sCC = 0
stack = []
conecctedComponents = []
maxValue = 0

def DFS1(s, graph, m):
  global stack
  m[s] = 1
  v = graph[s]
  for i in range(len(v)):
    a = v[i]
    if not(m[a]):
      DFS1(a, graph, m)
  
  stack.append(s)

def DFS2(s, graph, m):
  global stack, conecctedComponents, sCC, maxValue
  m[s] = 1
  v = graph[s]
  for i in range(len(v)):
    a = v[i]
    if not(m[a]):
      DFS2(a, graph, m)
  
  conecctedComponents[sCC] += 1
  if conecctedComponents[sCC] > maxValue:
    maxValue = conecctedComponents[sCC]


def kosaraju(n, graph, visited1, visited2):
  global stack, conecctedComponents, sCC

  ##Start first DFS Toposort
  for i in range(n):
    if not(visited1[i]):
      DFS1(i, graph, visited1)
  

  ##Do DFS in transpose graph
  while len(stack):
    s = stack.pop()
    if not(visited2[s]):
      DFS2(s, graph, visited2)
      sCC += 1

def main():
  global stack, conecctedComponents, sCC, maxValue
  cases = int(stdin.readline().strip())
  out = ""
  while cases:
    cases -= 1
    l = list(map(int,stdin.readline().strip().split()))
    n, m = l[0], l[1]
    graph = [ [] for i in range(n) ]
    visited1 = [0 for i in range(n)]
    visited2 = [0 for i in range(n)]
    conecctedComponents = [0 for i in range(n)]
    stack = []
    sCC = 0
    maxValue = 0

    for i in range(m):
      l = list(map(int,stdin.readline().strip().split()))
      a, b = l[0]-1, l[1]-1
      graph[a].append(b)
      graph[b].append(a)
    
    kosaraju(n, graph, visited1, visited2)
    out += str(maxValue) + "\n"
  print(out.strip())


main()