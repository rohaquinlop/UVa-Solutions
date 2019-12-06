/*
*
* Problema UVa 722 - Lakes
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

#define fl(i, a, b)	for (int i(a); i < (b); i ++)

#define all(v) 	(v).begin(), (v).end()
#define srt(v)	sort (all (v))

#define pb push_back
#define mp make_pair

#define dig(i)	(s[i] - '0')
#define slen(s)	s.length()

#define fr first
#define sc second

#define sz(x) ((int) (x).size())
#define fill (x, y)	memset(x, y, sizeof(x))
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

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int floodFill(vvi &graph, int y, int x, int& Y, int& X, int& c1, int& c2){
    if( y < 0 || y >= Y || x < 0 || x >= X ) return 0;
    if( graph[y][x] != c1 ) return 0;
    int ans = 1;
    graph[y][x] = c2;
    for(int d = 0; d < 4; d++)
        ans += floodFill(graph, y+dy[d], x+dx[d], Y, X, c1, c2);
    return ans;
}

int main() {
	FAST_IO;
    int cases, c = 0, water = 0, land = 1;
    string line;

    cin >> cases;
    getline(cin, line);
    getline(cin, line);

    while(cases--){
        c++;
        vvi graph;
        getline(cin, line);
        int xInit, yInit;
        sscanf( line.c_str(), "%d %d", &yInit, &xInit );
        while( getline(cin, line) ){
            if( line == "" ) break;
            else{
                //Ir creando la matriz
                vi temp;
                for( char c : line){
                    temp.pb(c-'0');
                }
                graph.pb(temp);
            }
        }
        //Hallar los componentes conectados
        int Y = graph.size(), X = graph[0].size();
        if( c > 1) cout << endl;
        cout << floodFill(graph, yInit-1, xInit-1, Y, X, water, land) << endl;
    }

	return 0;
}