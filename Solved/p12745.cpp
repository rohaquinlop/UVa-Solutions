/*
*
* Problema 12745 - Wishmaster
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

stack<int> pila;
int SCC;
map<int, int> connectedComponents;

void DFS1(int s, map<int, vector<int>> &graph, map<int, int> &visited){
	visited[s] = 1;
	vector<int> v = graph[s];
	for(int i = 0; i < v.size(); ++i ){
		int a = v[i];
		if(!visited[a]) DFS1(a, graph, visited);
	}
	pila.push(s);
}

void DFS2(int s, map<int, vector<int>> &graph, map<int, int> &visited){
	visited[s] = 1;
	vector<int> v = graph[s];
	for(int i = 0; i < v.size(); ++i ){
		int a = v[i];
		if(!visited[a]) DFS2(a, graph, visited);
	}
  connectedComponents[s] = SCC;
}

void kosaraju(int N, map<int, vector<int>> &graph, map<int, vector<int>> &graphT, map<int, int> &visited1, map<int, int> &visited2){
  map<int, vector<int>>::iterator it;
  for(it = graph.begin(); it != graph.end(); it++){
    if(!visited1[it->first]) DFS1(it->first, graph, visited1);
  }

	while(!pila.empty()){
		int s = pila.top();
		pila.pop();

		if(!visited2[s]){
			DFS2(s, graphT, visited2);
			++SCC;
		}
	}

}

int main() {
	FAST_IO;
  int T, N, M, i, j, k, cases = 0;
  
  cin >> T;

  while(T--){
    cin >> N >> M;
    cases++;

    map<int, vector<int>> graph;
    map<int, vector<int>> graphT;
    map<int, int> visited;
    map<int, int> visited1;
    connectedComponents = map<int, int>();
    SCC = 1;

    fl(i, 0, M){
      cin >> j >> k;
      graph[-j].push_back(k);
      graph[-k].push_back(j);

      graphT[k].push_back(-j);
      graphT[j].push_back(-k);
    }

    kosaraju(N, graph, graphT, visited, visited1);

    bool flag = true;

    for(i = 1; i <= N and flag; i++){
      if( connectedComponents.find(i) != connectedComponents.end() and connectedComponents.find(-i) != connectedComponents.end() ){
        if( connectedComponents[i] == connectedComponents[-i] ) flag = false;
      }
    }
    cout << "Case " << cases << ": ";
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
  }


	return 0;
}