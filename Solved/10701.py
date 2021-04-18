'''
*
* Problema UVa 10701 - Pre, in and post
*
'''

from sys import stdin

ans = ""

def indexValue(v, e):
  res = -1
  for i,x in enumerate(v):
    if(x == e):
      res = i
      break
  return res

def postorder(preorder, inorder):
  global ans
  posNode = indexValue(inorder, preorder[0])

  if posNode != 0:
    ##Significa que hay un sub-árbol izquierdo que falta por explorar
    postorder(preorder[1:posNode+1], inorder[:posNode])
  
  if posNode != len(inorder)-1:
    postorder(preorder[posNode+1:], inorder[posNode+1:])

  ans += preorder[0]

def main():
  global ans
  lines = stdin.readlines()
  i = 1
  while i < len(lines):
    ans = ""
    line = lines[i].strip().split()
    i += 1
    preorder = line[1]
    inorder = line[2]
    postorder(preorder, inorder)
    print(ans)


main()