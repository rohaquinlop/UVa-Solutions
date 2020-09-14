def lis(A):
  N,ans = len(A),0
  if N != 0:
    tab = [ 1 for _ in range(N) ]
    for n in range(1, N):
      for i in range(n):
        if tab[i]>=tab[n] and A[i]<=A[n]:
          tab[n] = tab[i]+1
      ans = max(ans, tab[n])
  return ans