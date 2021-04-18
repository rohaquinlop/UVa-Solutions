'''
*
* Problema UVa 10308 - Roads in the North
*
'''
from sys import stdin
from collections import *

graph = dict()
farest = []

def dfs(node, visited, depth):
  global graph, farest
  visited[node] = 1
  if farest == []:
    farest = [node, depth]
  else:
    if farest[1] < depth:
      farest = [node, depth]
  
  adj = graph[node]
  for x in adj:
    n, v = x[0], x[1]
    if visited[n] == -1:
      dfs(n, visited, v+depth)

def main():
  global graph, farest
  lines = stdin.readlines()
  lines = list(map(lambda x: list(map(int, x.strip().split())), lines))
  cases = []
  nCase = []
  for line in lines:
    if line == []:
      cases.append(nCase)
      nCase = []
    else:
      nCase.append(line)
  cases.append(nCase)
  out = ""
  for case in cases:
    ##Create the graph with weights
    visited = dict()
    visited1 = dict()
    graph = dict()
    start = -1

    for c in case:
      ##take the values
      a, b, d = c[0], c[1], c[2]
      start = a
      visited[a] = -1
      visited[b] = -1
      visited1[a] = -1
      visited1[b] = -1
      if a in graph.keys():
        graph[a].append([b, d])
      else:
        graph[a] = [[b, d]]
      
      if b in graph.keys():
        graph[b].append([a, d])
      else:
        graph[b] = [[a, d]]
    ##Do dfs since any node and find the farest node that can be reach
    farest = []
    dfs(start, visited, 0)
    dfs(farest[0], visited1, 0)
    out += str(farest[1]) + "\n"
  print(out.strip())

main()