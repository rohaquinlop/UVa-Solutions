
def upper(A, e):
  low = 0
  hi = len(A)

  while low < hi:
    mid = low + (hi-low)>>1

    if A[mid] == e:
      return mid
    elif A[mid] > e:
      hi = mid
    else:
      low = mid+1
  return low

def lower(A, e):
  low = 0
  hi = len(A)

  while low+1 < hi:
    mid = low + (hi-low)>>1
    if e <= A[mid]:
      hi = mid
    else:
      low = mid+1
  return low