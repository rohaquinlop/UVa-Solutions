/*
*
* Problema UVa 10596 - Morning Walk
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

void f(vvi &graph, vvi &visited, int node){
  for(int x : graph[node]){
    if( !visited[node][x] ){
      visited[node][x] = visited[x][node] = 1;
      f(graph, visited, x);
    }
  }
}

int main() {
	FAST_IO;
  int n, r, i, a, b, node;

  while(cin >> n >> r){
    vi degree(n, 0);
    vvi visited(n, vi(n, 0));
    vvi graph(n, vi(0));
    vpii edges;
    node = -1;

    fl(i, 0, r){
      cin >> a >> b;
      if(node == -1) node = a;
      degree[b]++;
      degree[a]++;
      graph[a].push_back(b);
      edges.push_back({a, b});
    }

    bool flag = true;

    fl(i, 0, n){
      if(degree[i]%2){
        flag = false;
        break;
      }
    }

    if(r == 0) cout << "Not Possible\n";
    else{
      if(flag){
        /*
        Ahora verificar que desde un nodo cualquiera se visite la cantidad de arcos que se indicaron
        Para esto se debe garantizar que al menos ese nodo tenga una arista en el grafo.
        Por lo que al hacer un DFS desde ese nodo se debe garantizar que la cantidad de aristas visitadas sean iguales.
        */

        f(graph, visited, node);
        for(pii p : edges){
          if( !visited[p.first][p.second] ){
            flag = false;
            break;
          }
        }

        if(flag) cout << "Possible\n";
        else cout << "Not Possible\n";
      }
      else cout << "Not Possible\n";
    }
  }


	return 0;
}