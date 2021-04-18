/*
*
* Problema UVa 796 - Critical Links
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

vi visited;
vi tin, low;
int timer;
vector<pair<int, int> > criticalLinks;

void isBridge(int v, int to){
  if( v < to )
    criticalLinks.pb( mp(v, to) );
  else criticalLinks.pb( mp(to, v) );
}

bool cmp( pair<int, int> &a, pair<int, int> &b ){
  if( a.first == b.first )
    return a.second < b.second;
  return a.first < b.first;
}

void dfs(int v, vvi &g,int p = -1){
  visited[v] = 1;
  tin[v] = low[v] = timer++;
  for(int to : g[v]){
    if(to == p) continue;
    if( visited[to]  ){
      low[v] = min(low[v], tin[to]);
    }
    else{
      dfs(to, g, v);
      low[v] = min(low[v], low[to]);
      if( low[to] > tin[v] )
        isBridge(v, to);
    }
  }
}

void findBridges(int n, vvi &g){
  int i;
  timer = 0;
  visited.assign(n, 0);
  tin.assign(n, -1);
  low.assign(n, -1);
  criticalLinks = vector<pair<int, int> >(0);
  fl(i, 0, n){
    if( !visited[i] ) dfs(i, g);
  }
}

int main() {
	FAST_IO;
  int n;
  int i, j, k, l, m;

  while (scanf("%d", &n) == 1){
    vvi g(n);
    fl(i, 0, n){
      scanf("%d (%d)", &j, &k);
      fl(l, 0, k){
        scanf("%d", &m);
        g[j].pb(m);
      }
    }
    findBridges(n, g);
    if( len(criticalLinks) > 0 ){
      //Iterate
      cout << len(criticalLinks) << " critical links" << endl;
      sort( criticalLinks.begin(), criticalLinks.end(), cmp );
      for( auto x : criticalLinks )
        cout << x.first << " - " << x.second << endl;
    }
    else cout << "0 critical links" << endl;
    cout << endl;
  }
  


	return 0;
}