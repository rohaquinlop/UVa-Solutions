/*
*
* Problema UVa 321 - The New Villa
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

bool isOff(int &node, vi &v){
  int i;
  fl(i, 0, v.size()) if( v[i] == 1 and i != node ) return false;
  return true;
}

int main() {
	FAST_IO;
  int r, d, s, i, j, k, c=0;
  string st, aux;

  while(cin >> r >> d >> s){
    if( r == 0 and d == 0 and s == 0 ) break;
    else{
      ++c;

      cout << "Villa #" << c << endl;

      //Construir grafo
      vvi graph(r, vi(0));
      vvi light(r, vi(0));

      fl(i, 0, d){
        cin >> j >> k;
        graph[j-1].push_back(k-1);
        graph[k-1].push_back(j-1);
      }

      fl(i, 0, s){
        cin >> j >> k;
        light[j-1].push_back(k-1);
      }
      
      //Iniciar el recorrido
      vi l(r, 0);
      queue< pair<int, vi> > cola;
      map< pair<int, vi>, int> visited;
      map< pair<int, vi>, pair< pair<int, vi>, string> > path;
      int node;
      l[0] = 1;
      pair<int , vi> p;
      bool flag = false;
      cola.push({0, l});
      visited[{0, l}] = 1;
      while(!cola.empty()){
        p = cola.front();
        cola.pop();
        node = p.first;
        l = p.second;
        if( node == r-1 and isOff(node, l)){
          flag = true;
          break;
        }
        fl(i, 0, light[node].size()){
          j = light[node][i];
          l[j] = !l[j];
          if( visited[ {node, l} ] != 1 and j != node){
            cola.push({node, l});
            visited[{node, l}] = 1;
            aux = to_string(j+1);
            if( l[j] ){
              st = "Switch on light in room " + aux;
            }
            else{
              st = "Switch off light in room " + aux;
            }
            path[ {node, l} ] = {p, st};
          }
          l[j] = !l[j];
        }

        fl(i, 0, graph[node].size()){
          j = graph[node][i];
          if( visited[{j, l}] != 1 and l[j] == 1 ){
            visited[{j, l}] = 1;
            cola.push({j, l});
            aux = to_string(j+1);
            st = "Move to room " + aux;
            path[ {j, l} ] = {p, st};
          }
        }
      }

      if( !flag ) cout << "The problem cannot be solved.\n";
      else{
        pair<int, vi> endP;
        endP.first = 0;
        endP.second = vi(r, 0);
        endP.second[0] = 1;
        vs res;

        while(p != endP){
          res.push_back(path[p].second);
          p = path[p].first;
        }
        cout << "The problem can be solved in " << res.size() << " steps:\n";
        for(i = res.size()-1; i >= 0; i--){
          cout << "- " << res[i] << ".\n";
        }
      }
      cout << endl;
    }
  }


	return 0;
}