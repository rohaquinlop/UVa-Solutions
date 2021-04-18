from sys import stdin

def main():
  lines = stdin.readlines()
  out = ""
  for nums in lines:
    nums = list(map(int, nums.strip().split()))
    accumTable = [0]
    minValFound = 0
    ans = 0
    for n in nums:
      accumTable.append(accumTable[len(accumTable)-1]+n)
    
    for i in range(len(accumTable)):
      if accumTable[i]-minValFound > ans:
        ans = accumTable[i]-minValFound
      if accumTable[i] < minValFound:
        minValFound = accumTable[i]
    
    out += str(ans) + "\n"
  
  print(out.strip())

main()