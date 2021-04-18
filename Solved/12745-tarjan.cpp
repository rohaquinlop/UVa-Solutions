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

int t;
stack<int> p;
map<int, int> SCC;

void DFS(int v, map<int, vector<int>>& graph, map<int, int>& visited, map<int, int>& secondTag, map<int, int>& isInStack);

void tarjan(map<int, vector<int>>& graph, map<int, int>& visited, map<int, int>& secondTag, map<int, int>& isInStack){
  map<int, vector<int>>::iterator it;
  for(it = graph.begin(); it != graph.end(); it++){
    if(!visited[it->first])
      DFS(it->first, graph, visited, secondTag, isInStack);
  }
}

void DFS(int v, map<int, vector<int>>& graph, map<int, int>& visited, map<int, int>& secondTag, map<int, int>& isInStack){
  int w;
  visited[v] = secondTag[v] = ++t;
  p.push(v);
  isInStack[v] = 1;

  for(int i = 0; i < graph[v].size(); ++i){
    w = graph[v][i];
    if(!visited[w]) DFS(w,graph, visited, secondTag, isInStack);
    if(isInStack[w])
      secondTag[v] = secondTag[v] < secondTag[w] ? secondTag[v] : secondTag[w];
  }

  if(secondTag[v] == visited[v]){
    while(p.top() != v){
      SCC[p.top()] = secondTag[v];
      isInStack[p.top()] = 0;
      p.pop();
    }
    SCC[p.top()] = secondTag[v];
    isInStack[p.top()] = 0;
    p.pop();
  }
}

int main() {
	FAST_IO;
  int T, N, M, i, j, k, cases = 0;
  
  cin >> T;

  while(T--){
    cin >> N >> M;
    cases++;
    t = 0;

    map<int, vector<int>> graph;
    map<int, int> visited, secondTag, isInStack;
    SCC = map<int, int>();

    fl(i, 0, M){
      cin >> j >> k;
      graph[-j].push_back(k);
      graph[-k].push_back(j);
    }

    tarjan(graph, visited, secondTag, isInStack);

    bool flag = true;

    for(i = 1; i <= N and flag; i++){
      if( SCC.find(i) != SCC.end() and SCC.find(-i) != SCC.end() ){
        if( SCC[i] == SCC[-i] ) flag = false;
      }
    }
    cout << "Case " << cases << ": ";
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
  }


	return 0;
}