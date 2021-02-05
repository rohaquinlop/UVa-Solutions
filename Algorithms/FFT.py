from math import *

def fft(A, invert):
  n = len(A)
  if n == 1:
    return A
  else:
    A0 = [ None for _ in range(n//2)] ##Array that contains even positions
    A1 = [ None for _ in range(n//2)] ##Array that contains odd positions

    i = 0
    while 2*i < n:
      A0[i] = A[2*i] ##Taking the even position
      A1[i] = A[2*i+1] ##Taking the odd position
      i += 1
    
    A0 = fft(A0, invert)
    A1 = fft(A1, invert)

    ang = 2*pi/n

    if invert:
      ang *= -1
    
    w = complex(1)
    wn = complex(cos(ang), sin(ang))

    i = 0
    while 2*i < n:
      A[i] = A0[i]+w*A1[i]
      A[i+n//2] = A0[i]-w*A1[i]

      if invert:
        A[i] /= 2
        A[i+n//2] /= 2
      
      w *= wn

      i += 1
    
    return A

def multiply(A, B):
  C = [None for _ in range(n)]

  n = 1
  while n < len(A)+len(B):
    n *= 2
  
  i = len(A)
  while i < n:
    A.append(complex(0))
    i += 1
  
  i = len(B)
  while i < n:
    B.append(complex(0))
    i += 1

  A = fft(A, False)
  B = fft(B, False)

  for i in range(n):
    C[i] = A[i]*B[i]
  
  C = fft(C, True)

  for i in range(n):
    C[i] = round(C[i].real)

  return C

def main():
  A = [complex(1), complex(2), complex(3), complex(4)]
  B = [complex(1), complex(2)]

  C = multiply(A, B)
  
  print(C)
  print( FFTBruteForce([1, 2, 3, 4], [1, 2]) )

main()


def FFTBruteForce(A, B):
  """
  Given 2 arrays A, B returns the multiplication of both arrays (Polynomial).
  """
  res = [0 for _ in range(len(A)+len(B)-1)]

  for i in range(len(A)):
    for j in range(len(B)):
      res[i+j] += ((A[i])*(B[j]))

  return res
