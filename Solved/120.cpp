/*
*
* Problema UVa 120 - Stacks of Flapjacks
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

void swapContent(vi &v, int idx, int n){
  vi tmp;
  int i;
  for(i = n-1; i >= idx+1; --i) tmp.push_back(v[i]);
  for(i = 0; i < idx; ++i) tmp.push_back(v[i]);
  tmp.push_back(v[idx]);
  fl(i, 0, tmp.size()){
    v[i] = tmp[i];
  }
}

bool isSorted(vi &v, int n){
  for(int i = n-1; i >= 0; --i){
    if( v[i] != n ) return false;
    n--;
  }
  return true;
}

int main() {
	FAST_IO;
  string line;
  int i, j, k, n, aux;

  while(getline(cin, line)){
    stringstream ss(line);
    vi v;

    while(ss >> i) v.push_back(i);

    n = v.size();
    vi tmp = v;
    sort(tmp.begin(), tmp.end());
    j = 1;
    int cnt = 0;

    cout << line << "\n";

    while(n > 1){
      if(v[0] == tmp[n-1]){
        //Verificar que se movió al tope el mayor de todos
        if(cnt > 0) cout << " ";
        cout << j;
        cnt++;
        j++;
        reverse(v.begin(), v.begin()+n);
        n--;
      }
      else if(v[n-1] == tmp[n-1]){
        n--;
        j++;
      }
      else{
        //Encontrar el número n en la pila y girar
        k = j;
        bool flag = false;
        for(i = n-1; i >= 0 and !flag; --i){
          k++;
          if(v[i] == tmp[n-1]){
            flag = true;
          }
        }
        i++;

        if(flag){
          if(cnt > 0) cout << " ";
          cout << k-1 << " " << j;
          cnt++;
          swapContent(v, i, n);
          n--;
          j++;
        }
      }
    }

    if(cnt > 0) cout << " ";
    cout << 0 << "\n";
  }

	return 0;
}