/*
*
* Problema 852 - Deciding victory in Go
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

int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

void solve(int w, int b, vector<string>& board, vector<vector<int>>& visited, vector<pair<int, int>> &dots){
  bool fW, fB;
  int cnt, x, y;
  for(pair<int, int> dot : dots){
    //dot = {x, y};
    if(!visited[dot.second][dot.first]){
      fW = false, fB = false, cnt = 1;

      stack<pair<int, int>> s;
      s.push(dot);
      visited[dot.second][dot.first]++;

      while(!s.empty()){
        pair<int, int> d = s.top();
        s.pop();

        if( board[d.second][d.first] == 'X' ) fB = true;
        else if( board[d.second][d.first] == 'O' ) fW = true;
        else if(board[d.second][d.first] == '.'){
          if(!visited[d.second][d.first]) cnt++;

          visited[d.second][d.first]++;

          for(int i = 0; i < 4; ++i){
            x = d.first + X[i];
            y = d.second + Y[i];
            if( x >= 0 and x < board[0].size() and y >= 0 and y < board.size() ){
              if(!visited[y][x]){
                s.push({x, y});
              }
            }
          }
        }
      }

      if( fB and !fW ) b += cnt;
      else if(fW and !fB) w += cnt;
    }
  }
  cout << "Black " << b << " White " << w << endl;
}

int main() {
	FAST_IO;
  int w, b, cases, i, j;

  cin >> cases;

  while(cases--){
    vector<string> board;
    vector<pair<int, int>> dots;
    w = 0, b = 0;
    string s;

    fl(i, 0, 9){
      cin >> s;
      board.pb(s);

      fl(j, 0, 9){
        if(s[j] == 'O') w++;
        else if(s[j] == 'X') b++;
        else{
          dots.pb({j, i});
        }
      }
    }

    vector<vector<int>> visited(9, vector<int>(9, 0));
    solve(w, b, board, visited, dots);

  }




	return 0;
}
