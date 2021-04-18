/*
*
* Problema UVa 10305 - Ordering Tasks
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

vi ans;
vvi nums;
vi visited;

//Do DFS
void dfs(int v){
  visited[v] = 1;
  for(int u : nums[v]){
    if(!visited[u]) dfs(u);
  }
  ans.pb(v);
}

int main() {
	FAST_IO;
  int n, m, i, j, k;

  while(cin >> n >> m){
    if(n == 0 and m == 0) break;
    nums = vvi(n);
    ans = vi();
    visited = vi(n, 0);
    fl(i, 0, m){
      cin >> j >> k;
      nums[j-1].pb(k-1);
    }

    fl(i, 0, n){
      if( !visited[i] ){
        dfs(i);
      }
    }

    reverse(ans.begin(), ans.end());
    
    fl(i, 0, len(ans)){
      cout << ans[i]+1;
      if( i < len(ans)-1 ) cout << " ";
    }
    cout << endl;
  }


	return 0;
}