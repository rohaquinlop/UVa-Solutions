/*
*
* UVa 1733 - Design New Capital
*
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

typedef vector < pii > vpii;
typedef vector < pll > vpll;

typedef vector <string> vs;
typedef vector < vi > vvi;
typedef vector < vll > vvll;

#define fl(i, a, b)	for (int i = a; i < b; ++i)

#define all(v) 	(v).begin(), (v).end()
#define srt(v)	sort (all (v))

#define pb push_back
#define mp make_pair

#define dig(i)	(s[i] - '0')
#define slen(s)	s.length()

#define fr first
#define sc second

#define len(x) x.size()
#define fill(x, y)	memset(x, y, sizeof(x))
#define clr(a)	fill(a, 0)
#define endl '\n'

#define PI 3.14159265358979323

#define trace1(x1)					cerr << #x1 << ": " << x1 << endl;
#define trace2(x1, x2)				cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << endl;
#define trace3(x1, x2, x3)			cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 << ": " << x3 << endl;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int ROOT = 5;
const int N = 7340033;
const int MOD = 7340033;
const int ROOT_1 = 4404020;
const int ROOT_PW = 1 << 20;

void initValues(vll &factorial, vll &inverse){
  int i;
  for(i = 1; i < N; i++){
    factorial[i] = (factorial[i-1] * (i%MOD))%MOD;
  }

  inverse[1] = 1;
  for(i = 2; i < N; i++){
    inverse[i] = (MOD - (MOD/i) * inverse[MOD%i]%MOD)%MOD;
  }
}

int getQuadrant(int x, int y){
  if(x > 0 && y > 0) return 0;
  if(x < 0 && y > 0) return 1;
  if(x < 0 && y < 0) return 2;
  return 3;
}

ll C(int n, int k, vll& factorial, vll& inverse){
  if(k == 0 or k == n) return 1;
  return (factorial[n] * inverse[ (factorial[k]*factorial[n-k])%MOD ] ) % MOD;
}

vll polynomial(int x, int y, vll& factorial, vll& inverse){
  vll ans;
  int k = min(x, y), i = 0;

  while(i <= k){
    ans.push_back( (C(x, i, factorial, inverse) * C(y, i, factorial, inverse))%MOD );
    i++;
  }

  return ans;
}

void ntt(vector<long long>& a, bool flag, int n, vll& inverse){
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
    v = inverse[n];
    for(i = 0; i < n; ++i)
      a[i] = (1LL * a[i] * v % MOD);
  }
}

void multiplicarPolinomios(vector<long long>& compA, vector<long long>& compB, int n, vll& inverse){
  ntt(compA, false, n, inverse);
  ntt(compB, false, n, inverse);
  
  for(int i = 0; i < n; ++i)
    compA[i] = compA[i] * compB[i] % MOD;

  ntt(compA, true, n, inverse);
}

void solve(vi &quadrants, vll& factorial, vll& inverse, int n){
  int aux = 1;

  vll poly1 = polynomial(quadrants[0], quadrants[2], factorial, inverse);
  vll poly2 = polynomial(quadrants[1], quadrants[3], factorial, inverse);

  while(aux < poly1.size() + poly2.size()) aux <<= 1;

  poly1.resize(aux, 0);
  poly2.resize(aux, 0);

  //answer is in poly1
  multiplicarPolinomios(poly1, poly2, aux, inverse);

  int i, j = 1;

  while(poly1[aux-1] == 0){
    aux--;
  }

  for(i = 0; i < n; i++){
    if( (i+1)%2 != 0 or ((i+1)%2 == 0 and j >= aux+1 )) cout << 0;
    else cout << poly1[j++];

    if(i < n-1) cout << " ";
  }
  cout << endl;
}

int main() {
	FAST_IO;

  int T, n, x, y, cases = 0, i;
  vll inverse(N, 0);
  vll factorial(N, 1);
  initValues(factorial, inverse);

  cin >> T;

  while(T--){
    cases++;
    cin >> n;
    i = 0;

    vi quadrants(4, 0);

    while(i < n){
      cin >> x >> y;
      quadrants[getQuadrant(x, y)]++;
      i++;
    }

    cout << "Case " << cases << ":\n";
    solve(quadrants, factorial, inverse, n);
  }

	return 0;
}