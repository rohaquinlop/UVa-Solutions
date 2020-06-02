/*
*
* Problema UVa 558 - Wormholes
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

class Arista{
public:
  int x, y, t;

  Arista(int a, int b, int c){
    this->x = a;
    this->y = b;
    this->t = c;
  }
};

int main() {
	FAST_IO;
  int cases, n, m, i, j, aux;
  int x, y, t;

  cin >> cases;

  while(cases--){
    cin >> n >> m;
    vector<Arista> aristas;
    fl(i, 0, m){
      cin >> x >> y >> t;
      aristas.push_back(Arista(x, y, t));
    }

    vi d(n);

    fl(i, 0, n){
      x = -1;
      for(Arista e : aristas){
        if( d[e.x] + e.t < d[e.y] ){
           d[e.y] = d[e.x] + e.t;
           x = e.y;
        }
      }
    }

    if(x == -1) cout << "not possible\n";
    else cout << "possible\n";

  }


	return 0;
}