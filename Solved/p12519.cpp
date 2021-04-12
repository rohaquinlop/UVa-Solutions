/*
*
* Problema 12519 - The Farnsworth Parabox
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

class Edge{
public:
  int a;
  int b;
  int cost;

  Edge(int _a, int _b, int _c){
    a = _a;
    b = _b;
    cost = _c;
  }
};

bool solve(vector<Edge>& v, int n){
  int x;
  vi d(n), p(n, -1);

  for (int i = 0; i < n; ++i) {
    x = -1;
    for (Edge e : v) {
      if (d[e.a] + e.cost < d[e.b]) {
        d[e.b] = d[e.a] + e.cost;
        p[e.b] = e.a;
        x = e.b;
      }
    }
  }

  if(x == -1) return false;
  return true;
}

int main() {
	FAST_IO;
  int N, B, i, j, k, t;

  while(cin >> N >> B){
    if(N == 0 and B == 0) break;

    vector<Edge> graph;

    fl(i, 0, B){
      cin >> j >> k >> t;
      j--, k--;
      graph.push_back(Edge(j, k, -t));
      graph.push_back(Edge(k, j, t));
    }

    if(solve(graph, N)) cout << "Y\n";
    else cout << "N\n";


  }
  


	return 0;
}