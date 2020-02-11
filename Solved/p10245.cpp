/*
*
* Problema UVa 10245 - The Closest Pair Problem
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

class Point{
public:
  long double x;
  long double y;
  Point(long double a, long double b){
    x = a;
    y = b;
  }
};

bool cmpX(Point &a, Point &b){
  if( a.x == b.x ) return a.y < b.y;
  return a.x < b.x;
}

long double minVal(long double a, long double b){
  return a < b? a:b;
}

long double distancePoints(Point &a, Point &b){
  // cout << a.x << " " << a.y << " ; " << b.x << " " << b.y << endl;
  long double val = ((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y));
  // cout << val << " " << sqrt(val) << endl;
  return sqrt(val);
}

long double minDistanceSets(vector<Point> a, vector<Point> b, long double x, long double w){
  vector<Point> s;
  int i, j;

  //Tomando de a como si fuera el arreglo de izq
  //Tomando de b como si fuera el arreglo de der

  i = len(a)-1;

  while(i >= 0){
    if( x-a[i].x <= w ){
      s.pb(a[i]);
    }
    else break;
    --i;
  }

  i = 0;
  while(i < len(b)){
    if( b[i].x-x <= w ){
      s.pb(b[i]);
    }
    else break;
    ++i;
  }

  long double minDist = distancePoints( a[0], b[0] );

  fl(i, 0, len(a)){
    fl(j, 0, len(b)){
      minDist = minVal( minDist, distancePoints(a[i], b[j])  );
    }
  }

  return minDist;
}

pair< vector<Point>, vector<Point> > split(vector<Point> v){
  vector<Point> s1;
  int n = (len(v)-1)>>1;
  int i = len(v);
  while( i > n){
    s1.push_back(v[i-1]);
    v.pop_back();
    i--;
  }
  // cout << len(s1) << " " << len(v) << endl;
  reverse(s1.begin(), s1.end());
  return make_pair(v, s1);
}

long double aux(vector<Point> v){
  // for(auto x : v){
  //   cout << x.x << " " << x.y << " - ";
  // }
  // cout << endl;
  if( len(v) == 1 ) return 10000.0;
  else if( len(v) == 2 ) return distancePoints(v[0], v[1]);
  else{
    pair< vector<Point>, vector<Point> > vecs = split(v);
    vector<Point> s1 = vecs.first;
    vector<Point> s2 = vecs.second;
    long double d1 = aux(s1);
    long double d2 = aux(s2);
    long double d3 = minDistanceSets(s1, s2, s1[len(s1)-1].x, minVal(d1, d2));
    // cout << d1 << " " << d2 << " " << d3 << endl;
    return minVal( d3, minVal(d1, d2) );
  }
}

int main() {
	FAST_IO;
  int n, i;
  long double x, y;

  while( cin >> n){
    if(!n) break;
    vector<Point> p;
    fl(i, 0, n){
      cin >> x >> y;
      p.pb(Point(x+0.0, y+0.0));
    }
    if( n == 1 ) cout << "INFINITY\n";
    else{
      sort(p.begin(), p.end(), cmpX);

      //Divide & Conquer
      long double res = aux(p);
      if( res < 10000) cout << fixed << setprecision(4) << res << endl;
      else cout << "INFINITY\n";
    }
  }


	return 0;
}