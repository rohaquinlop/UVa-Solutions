from sys import stdin

memo = []

def LCS(S, T, n, m):
  global memo
  if memo[n][m] != -1:
    return memo[n][m]
  if n <= 0 or m <= 0:
    memo[n][m] = 0
  else:
    if S[n-1] == T[m-1] and n > 0 and m > 0:
      memo[n][m] = 1 + LCS(S, T, n-1, m-1)
    else:
      memo[n][m] = max(LCS(S, T, n-1, m), LCS(S, T, n, m-1))
  return memo[n][m]

def main():
  global memo
  A = "bcacbcabbaccbab"
  B = "bccabccbbabacbc"
  memo = [ [-1 for i in range(len(B)+1)] for j in range(len(A)+1) ]
  print(LCS(A, B, len(A), len(B)))

main()