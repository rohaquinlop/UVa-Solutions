/*
*
* Problema UVa 200 - Rare Order
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

void dfs(char c, map<char, vector<char>>& graph, map<char, bool> &visited,vector<char>& res){
	visited[c] = true;
	for( char v : graph[c] ){
		if(!visited[v]){
			dfs(v, graph, visited, res);
		}
	}
	res.push_back(c);
}

int main() {
	FAST_IO;
	string line;
	vs lines;

	while(getline(cin, line)){
		if(line == "#"){
			//Create the graph
			map<char, vector<char>> graph;
			vector<char> appeared;
			map<char, bool> visited;

			for(int i = 0; i < lines.size()-1; ++i){
				int n = min( lines[i].size(), lines[i+1].size() );
				for(int j = 0; j < n; ++j){
					if( lines[i][j] != lines[i+1][j] ){
						graph[lines[i][j]].push_back(lines[i+1][j]);
						appeared.push_back( lines[i][j] );
						break;
					}
				}
			}

			//Iterate over graph
			vector<char> res;

			for(char c : appeared){
				if(!visited[c]){
					dfs(c, graph, visited, res);
				}
			}

			reverse(res.begin(), res.end());

			for(char c : res){
				cout << c;
			}
			cout << endl;
			lines = vs();
		}
		else lines.push_back(line);
	}


	return 0;
}