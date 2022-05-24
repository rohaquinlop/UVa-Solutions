/*
*
* UVa 11584 - Partitioning by Palindromes
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

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T power(T x, T y, ll m = MOD) { T ans = 1; x %= m; while (y > 0) { if (y & 1ll) ans = (ans * x) % m; y >>= 1ll; x = (x * x)%m; } return ans%m;}

bool isPalindrome(string& s, int i, int j){
  int idx = 1;

  while(i < j){
    if( s[i++] != s[j--] ) return false;
  }

  return true;
}

int solve(string& s){
  int n = len(s);
  int i, j, k, L;

  vi C(n);
  vector<vector<bool>> P(n, vector<bool>(n));

  for(i =0; i < n; i++) P[i][i] = true;

  for(L = 2; L <= n; L++){
    for(i = 0; i < n-L+1; i++){
      j = i + L-1;

      if(L == 2) P[i][j] = (s[i] == s[j]);
      else P[i][j] = (s[i] == s[j]) and P[i+1][j-1];
    }
  }

  for(i = 0; i < n; i++){
    if(P[0][i] == true) C[i] = 0;
    else{
      C[i] = 1000;
      for(j = 0; j < i; j++){
        if(P[j+1][i] and 1 + C[j] < C[i]) C[i] = 1 + C[j];
      }
    }
  }

  return C[n-1];
}

int main() {
	FAST_IO;
  int T;
  string s;

  cin >> T;

  while(T--){
    cin >> s;

    cout << solve(s) + 1 << endl;
  }


	return 0;
}