from math import ceil
from sys import stdin

def solve(A : list[int], tSum : list[int], N : int, k : int) -> list[list[int]]:
  ans : list[list[int]] = []
  if k == 1:
    ans.append(A[:N])
  else:
    lo, hi = k, N # [lo, hi)
    
    while lo < hi:
      mid = (hi+lo)>>1
      
      accumRight = tSum[N-1] - tSum[mid]
      target = tSum[mid-1]//k
      
      if accumRight < target:
        hi = mid
      else:
        lo = mid+1
    
    ans = solve(A, tSum, lo, k-1)
    ans.append(A[lo:N])
  return ans

def main():
  lines = stdin.readlines()
  i = 1
  
  while i < len(lines):
    m, k = map(int, lines[i].strip().split())
    P = list(map(int, lines[i+1].strip().split()))
    accum = 0
    tSum = [0 for _ in range(m)]
    tSum = [P[j] if j == 0 else P[j]+tSum[j-1] for j in range(m)]
    
    i += 2
    
    print(solve(P, tSum, m, k))
    print("-------------\n")

if __name__ == "__main__":
  main()