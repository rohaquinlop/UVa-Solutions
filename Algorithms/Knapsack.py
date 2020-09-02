w = [12, 2, 1, 1, 4] #[7, 5, 6, 8] #[6, 3, 4, 7]
b = [4, 2, 1, 2, 10] #[3, 2, 1, 4] #[3, 1, 5, 2]
N = len(w)
M = 15 #20
MAX = 10000

mem = [[-1 for i in range(10000)] for i in range(1000)]

# solution divide and conquer
def morral(m, n):
    global w, b
    
    if n == 0:
        if m >= w[n]: return b[n]
        else: return 0
    else:
        if m - w[n] >= 0: return max(morral(m, n - 1), morral(m - w[n], n - 1) + b[n])
        else: return morral(m, n - 1)

# dp solution with memoization
def morralMem(m, n):
    global w, b

    if mem[m][n] != -1: return mem[m][n]
    else:
        if n == 0:
            if m >= w[n]: mem[m][n] = b[n]
            else: mem[m][n] = 0
            return mem[m][n]
        else:
            mem[m][n] = max(morralMem(m, n - 1), morralMem(m - w[n], n - 1) + b[n])
            return mem[m][n]

# dp solution with tabulation
def morralTab(M, N, w, b):
    tab = [[0 for _ in range(N)] for _ in range(M + 1)]

    for m in range(M + 1):
        if m - w[0] >= 0: tab[m][0] = b[0]

    for m in range(1, M + 1):
        for n in range(1, N):
            if m - w[n] >= 0:
                tab[m][n] = max(tab[m][n - 1], tab[m - w[n]][n - 1] + b[n])
            else:
                tab[m][n] = tab[m][n - 1]
                
    return tab[M][N - 1]

# dp solution with opt. tabulation
def morralTabOpt(M, N, w, b):
    tab = [0 for _ in range(M + 1)]

    for n in range(0, N):
        for m in range(M, -1, -1):
            if m - w[n] >= 0: tab[m] = max(tab[m], tab[m - w[n]] + b[n])

    return tab[M]
 
print(morral(M, N - 1))
print(morralMem(M, N - 1))
print(morralTab(M, N, w, b))
print(morralTabOpt(M, N, w, b))
