"""
*
* Problema UVa 524 - Prime Ring Problem
*
"""

from sys import stdin, stdout

primes = [0 for n in range(101)]
aux = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]

def solve(lst, n):
  global primes
  if len(lst) == n:
    ans = ""
    for i in range(n):
      ans += str(lst[i])
      if i < n-1:
        ans += " "
    ans += "\n"
    stdout.write(ans)
  else:
    for i in range(2, n+1):
      if i not in lst and primes[lst[-1]+i]:
        if len(lst) == n-1 and primes[lst[0]+i]:
          lst.append(i)
          solve(lst, n)
          lst.pop()
        elif len(lst)  != n-1:
          lst.append(i)
          solve(lst, n)
          lst.pop()

def main():
  for i in aux:
    primes[i] = 1
  lines = stdin.readlines()
  cases = 0

  for line in lines:
    cases += 1
    n = int(line.strip())

    stdout.write("Case {}:\n".format(cases))
    solve([1],  n)
    if(cases < len(lines)):
      stdout.write("\n")

main()