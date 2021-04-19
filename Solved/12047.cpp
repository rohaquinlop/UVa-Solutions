/*
*
* Problema 12047 - Highest Paid Toll
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

const int INF = 1000001;

void inicializar(int s, vi &d, int n){
  for(int i = 0; i < n; ++i){
    d[i] = INF;
  }

  d[s] = 0;
}

void dijkstra(int s, vi &d, vector<vector<pii>>& graph){
  int i, j, k, u, v, peso, costo;
  int n = graph.size();
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > cola;
  
  inicializar(s, d, n);
  cola.push(make_pair(0, s));

  while(!cola.empty()){
    costo = cola.top().first;
    u = cola.top().second;
    cola.pop();

    if(costo == d[u]){
      for(j = 0; j < graph[u].size(); ++j){
        v = graph[u][j].first;
        peso = graph[u][j].second;
        if(d[u] != INF && d[u] + peso < d[v]){
          d[v] = d[u] + peso;
          cola.push(make_pair(d[v], v));
        }
      }
    }
  }
}

int main() {
	FAST_IO;
  int T, N, M, s, t, p, u, v, c, ans;

  cin >> T;
  
  while(T--){
    ans = -1;
    cin >> N >> M >> s >> t >> p;
    s--, t--;

    vector<vector<pair<int, int>>> graph(N);
    vector<vector<pair<int, int>>> graphInverse(N);

    for(int i = 0; i < M; i++){
      cin >> u >> v >> c;
      u--, v--;
      graph[u].push_back({v, c});
      graphInverse[v].push_back({u, c});
    }

    vi dS(N), dT(N);

    dijkstra(s, dS, graph);
    dijkstra(t, dT, graphInverse);

    for(int i = 0; i < N; i++){
      for(pii edge : graph[i]){
        int v = edge.first;

        if( dS[i] + edge.second + dT[v] <= p ) ans = max(edge.second, ans);
      }
    }

    cout << ans << endl;

  }

	return 0;
}