'''
*
* Problema UVa 11111 - Generalized Matrioshkas
*
'''
from sys import stdin

def aux(nums, father, idx, n):
	if idx == n:
		return True
	elif n-idx == 2:
		return -1*nums[idx] < father
	ans = True
	internalSum = 0
	openVal = -1
	j = idx

	for i in range(idx, n):
		if nums[i] < 0 and openVal == -1:
			openVal = -1*nums[i]
			j = i
		elif nums[i] == openVal:
			ans = ans and aux(nums, openVal, j+1, i)
			openVal = -1
			j = i
			internalSum += nums[i]

	return internalSum < father and ans and j != idx and openVal == -1

def solve(nums, father, idx, n):
	ans = True
	stack = []

	for num in nums:
		if num < 0:
			stack.append(num)
		else:
			if stack:
				if num == -1*stack[-1]:
					stack.pop()
				else:
					ans = False
			else:
				ans = False

	if stack:
		ans = False
	elif ans:
		ans = aux(nums, father, idx, n)

	return ans

def main():
	output = ""
	lines = stdin.readlines()

	for line in lines:
		nums = list(map(int, line.strip().split()))

		if solve(nums, float("inf"), 0, len(nums)):
			output += ":-) Matrioshka!\n"
		else:
			output += ":-( Try again.\n"
	print(output, end="")


main()