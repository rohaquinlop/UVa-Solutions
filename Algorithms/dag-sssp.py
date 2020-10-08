from sys import stdin
from collections import deque

INF = float('inf')
MAX = 10000
adj, inc = [[] for i in range(MAX)], [0 for i in range(MAX)]
n = int()

def topoSort():
    topo, cola, vis = [], deque(), 0
    for i in range(n):
        if inc[i] == 0: cola.append(i)

    while len(cola) != 0:
        v = cola.popleft()
        topo.append(v)

        for i in range(len(adj[v])):
            u = adj[v][i][0]
            inc[u] -= 1
            if inc[u] == 0: cola.append(u)
        vis += 1

    if vis != n: return None
    else: return topo

def sssp(s):
    d, p = [INF for i in range(MAX)], [-1 for i in range(MAX)]
    d[s] = 0
    topo = topoSort()
    for u in topo:
        for v, w in adj[u]:
            if d[u] + w < d[v]:
                d[v], p[v] = d[u] + w, u
    return d, p

def main():
    global n
    n, m = list(map(int, stdin.readline().split()))

    for i in range(m):
        u, v, w = list(map(int, stdin.readline().split()))
        adj[u].append((v, w))
        inc[v] += 1

    print("Grafo")
    for i in range(n):
        print("Nodo %d:" % i)
        for j in range(len(adj[i])):
            print("%d" % adj[i][j][0], end = ' ')
        print("")

    print("Caminos más cortos:")
    dist, pred = sssp(1)
    for i in range(n):
        print("%f%c" %(dist[i], '\n' if i == n - 1 else ' '), end = '')

main()

    
    
