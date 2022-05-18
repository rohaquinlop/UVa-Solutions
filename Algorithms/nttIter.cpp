/*
Carlos Ramirez
Number Theoretic Transform (NTT) - Implementacion iterativa
Mayo 27 de 2020

*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

const int MOD = 7340033;
const int ROOT = 5;
const int ROOT_1 = 4404020;
const int ROOT_PW = 1 << 20;

long long powMod(long long n, long long e, long long m){
  long long x = 1;
  n = (n >= m) ? n % m : n;

  while(e > 0){
    if(e % 2 == 1)
      x = x * n % m;
    n = n * n % m;
    e /= 2;
  }

  return x;
}

long long inverso(long long n, long long m){
  return powMod(n, m - 2, m);
}

void ntt(vector<long long>& a, bool flag, int n){
  int i, aux, k, j, bit;
  long long exp, w, v, u;

  for(i = 1, j = 0; i < n; ++i){
    bit = n >> 1;
    
    while(j & bit){
      j ^= bit;
      bit >>= 1;
    }
    j ^= bit;

    if(i < j)
      swap(a[i], a[j]);
  }

  for(k = 2; k <= n; k <<= 1){
    exp = (flag) ? ROOT_1 : ROOT;

    for(i = k; i < ROOT_PW; i <<= 1)
      exp = (1LL * exp * exp % MOD);
    
    for(i = 0; i < n; i += k){
      w = 1;
      for(j = 0; j < k / 2; ++j){
        u = a[i + j];
        v = (1LL * a[i + j + (k / 2)] * w % MOD);
        a[i + j] = u + v < MOD ? u + v : u + v - MOD;
        a[i + j + (k / 2)] = u - v >= 0 ? u - v : u - v + MOD;
        w = (1LL * w * exp % MOD);
      }
    }
  }

  if(flag){
    v = inverso(n, MOD);
    for(i = 0; i < n; ++i)
      a[i] = (1LL * a[i] * v % MOD);
  }
}

void multiplicarPolinomios(vector<long long>& compA, vector<long long>& compB, int n){
  ntt(compA, false, n);
  ntt(compB, false, n);
  
  for(int i = 0; i < n; ++i)
    compA[i] = compA[i] * compB[i] % MOD;

  ntt(compA, true, n);
}

int main(){
  int i, aux, ac, arr1[] = {4, 3, 6, 5}, arr2[] = {2, 7, 3, 8}, arr3[] = {1, 2, 3, 4};
  vector<long long> pol1(arr1, arr1 + 4), pol2(arr2, arr2 + 4);
  vector<long long> pol3(arr3, arr3 + 4);

  aux = 1;
  while(aux < pol1.size() + pol2.size())
    aux <<= 1;

  pol1.resize(aux);
  pol2.resize(aux);
  
  multiplicarPolinomios(pol1, pol2, aux);

  //si los elementos de los vectores representan los coeficientes de dos
  //polinomios, entonces el resultado corresponde a los coeficientes del producto
  for(i = 0; i < aux; ++i)
    printf("%lli ", pol1[i]);
  printf("\n");

  ac = 0;

  //si los elementos representan los digitos de un numero grande
  for(i = 0; i < pol1.size(); ++i){
    aux = pol1[i];
    aux += ac;
    ac = aux / 10;
    pol1[i] = aux % 10;
  }

  for(i = 0; i < pol1.size(); ++i)
    printf("%lli ", pol1[i]);
  printf("\n");

  return 0;
}
