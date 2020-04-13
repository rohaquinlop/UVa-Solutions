'''
*
* Problema UVa 872 - Ordering
*
'''

from sys import stdin
out = ""

def toposort(visited, graph, indegree, path, nodes):
  global out
  flag  = False;

  for i in range(26):
    if indegree[i] == 0 and visited[i] == 0 and ( i in nodes ):
      adj = graph[i];
      for j in adj:
        indegree[j] -= 1
      
      path.append(i);
      visited[i] = 1;
      toposort(visited, graph, indegree, path, nodes);

      visited[i] = 0;
      path.pop();
      for j in adj:
        indegree[j] += 1;
      
      flag = True;
  
  if not(flag):
    for i in range(len(path)):
      out += chr(65+path[i]);
      if i < len(path)-1:
        out += " ";
    if( len(path) == 0 ):
      out += "NO";
    out += "\n"

def main():
  global out
  lines = stdin.readlines();
  i = 2;
  out = "";
  while i < len(lines):
    nodes = lines[i];
    edges = lines[i+1];
    if(i > 2):
      out += "\n";
    i += 3;
    nodes = list(map(lambda x : ord(x)-65, nodes.strip().split()));
    edges = edges.strip().split();
    graph = [ [] for _ in range(26) ];
    indegree = [0 for _ in range(26) ];
    visited = [0 for _ in range(26) ];
    
    for edge in edges:
      a, b = ord(edge[0])-65, ord(edge[2])-65;
      indegree[b] += 1;
      graph[a].append(b);
    
    path = [];
    toposort(visited, graph, indegree, path, nodes);
  
  print(out.strip());


main();