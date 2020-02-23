"""
*
* Problema UVa 299 - Train Swapping
*
"""
from sys import *
count = 0

def concatenate(a, b):
  global count
  res = []
  i = 0
  j = 0
  while (i < len(a)) or (j < len(b)):
    if i == len(a):
      res.append(b[j])
      j += 1
    elif j == len(b):
      res.append(a[i])
      i += 1
    else:
      if a[i] <= b[j]:
        res.append(a[i])
        i += 1
      else:
        res.append(b[j])
        count += len(a)-i
        j += 1
  return res

def divideLst(lst):
  res = []
  mid = len(lst)//2
  i = 0
  while i < mid:
    res.append(lst[i])
    i += 1
  return res, lst[i::]


def mergeSort(lst):
  if len(lst) == 1:
    return lst
  else:
    a, b = divideLst(lst)
    return concatenate(mergeSort(a), mergeSort(b))

def main():
  global count
  lines = stdin.readlines()
  lines = list(map(int, (" ".join(map(lambda x: x.strip(), lines))).split()))
  i = 1
  out = ""
  while i < len(lines):
    count = 0
    elem = lines[i]
    nums = []
    i += 1
    j = 0
    while j < elem:
      nums.append(lines[i])
      i += 1
      j += 1
    if elem > 0:
      nums = mergeSort(nums)
    out += "Optimal train swapping takes {0} swaps.\n".format(count)
  print(out.strip())

main()