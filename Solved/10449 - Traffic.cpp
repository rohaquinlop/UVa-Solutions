/*
*
* Problema 10449 - Traffic
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
const int INF = 1e8+9;

template <typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T power(T x, T y, ll m = MOD) { T ans = 1; x %= m; while (y > 0) { if (y & 1ll) ans = (ans * x) % m; y >>= 1ll; x = (x * x)%m; } return ans%m;}


struct  edge{
  int a, b, cost;

  edge(int a1, int b1, int cost1){
    a = a1;
    b = b1;
    cost = cost1;
  }
};

vi bellmanFord(int v, int n, int r, vector<edge> &e){
  int i, j;
  vi d(n, INF);
  d[v] = 0;
  fl(i, 0, n-1){
    fl(j, 0, r){
      if( d[e[j].a] != INF and d[e[j].b] > d[e[j].a] + e[j].cost){
        d[e[j].b] = d[e[j].a] + e[j].cost;
      }
    }
  }

  fl(i, 0, n){
    fl(j, 0, r){
      if( d[e[j].b] > d[e[j].a] + e[j].cost ){
        d[e[j].b] = -INF;
      }
    }
  }

  return d;
}

int main() {
	FAST_IO;
  int n, r, q, a, b, i, tmp, c = 0;

  while( cin >> n){
    c++;
    vi busynes;
    vector<edge> e;

    fl(i, 0, n){
      cin >> a;
      busynes.push_back(a);
    }

    cin >> r;
    fl(i, 0, r){
      cin >> a >> b;
      a--, b--;
      tmp = busynes[b]-busynes[a];
      tmp = tmp*tmp*tmp;
      e.push_back(edge(a, b, tmp));
    }
    vi d = bellmanFord(0, n, r, e);

    cout << "Set #" << c << endl;
    cin >> q;
    fl(i, 0, q){
      cin >> b;
      b--;
      if(d[b] < 3 or d[b] == INF) cout << "?" << endl;
      else cout << d[b] << endl;
    }
  }

	return 0;
}