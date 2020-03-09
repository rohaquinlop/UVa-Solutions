'''
*
* Problema UVa 572 - Oil Deposits
*
'''

from sys import stdin, stdout

def main():
  ##Rotations in the graph
  dx = [-1, 0, 1, -1, 1, -1, 0, 1]
  dy = [-1, -1, -1, 0, 0, 1, 1, 1]
  lines = stdin.readlines()
  i = 0
  while i < len(lines):
    line = list(map(int, lines[i].strip().split()))
    rows, columns = line[0], line[1]
    if rows == 0 and columns == 0:
      break
    ##Creating the graph
    graph = []
    stack = []
    i += 1
    for j in range(rows):
      #graph.append( [char for char in lines[i].strip() ] )
      line = lines[i].strip()
      t = []
      for k in range(len(line)):
        if line[k] == '@':
          stack.append([k, j])
        t.append(line[k])
      graph.append(t)
      i += 1
    ##Visited Matrix
    #visited = [ [ 0 for _ in range(columns) ] for j in range(rows) ]
    #Graph Traversal
    count = 0
    while len(stack) > 0:
      t = stack.pop()
      c, r = t[0], t[1]

      if graph[r][c] == '@':
        count += 1
        graph[r][c] = '*'

      for j in range(8):
        dc, dr = c+dx[j], r+dy[j]
        if (0 <= dc < columns) and (0 <= dr < rows) and graph[dr][dc] == '@':
          graph[dr][dc] = '*'
          stack.append([dc, dr])
    
    print(count)

main()