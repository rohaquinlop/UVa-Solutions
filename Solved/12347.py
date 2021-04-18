'''
*
* Problema UVa 12347 - Binary Search Tree
*
'''

import sys
from sys import stdin

ans = ""
idx = 0

def postOrder(preorder, minVal, maxVal):
	global idx, ans
	if idx == len(preorder):
		return
	
	node = preorder[idx]
	
	if node < minVal or node > maxVal:
		return
	
	idx += 1

	postOrder(preorder, minVal, node)
	postOrder(preorder, node, maxVal)

	ans += str(node) + "\n"

def main():
	global ans
	preorder = stdin.readlines()
	preorder = list(map(lambda x : int(x.strip()), preorder))
	postOrder(preorder, 0, 10**6)
	print(ans.strip())

main()