/*
*
* Problema 10044 - Erdös Numbers
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

vector<string> parseInput(string &line){
  int i;
  bool f = false, dot = false;
  vector<string> ans;
  string s;


  fl(i, 0, len(line)){
    if(dot) s += line[i];
    else{
      if(line[i] == ',' and !f){
        f = true;
        s += line[i];
      }
      else if(line[i] == ',' or line[i] == ':'){
        ans.pb(s);
        s = "";
        if(line[i] == ':') dot = true;
        i++;
        f = false;
      }
      else
        s += line[i];
    }
  }
  ans.pb(s);

  return ans;
}

void solve(map<string, vs>& authors, map<string, int>& memo, string author){
  map<string, bool> visited;
  queue<string> q;
  string tope;

  q.push(author);
  visited[author] = true;
  memo[author] = 0;

  while(!q.empty()){
    tope = q.front();
    q.pop();
    for(string co : authors[tope]){
      if( !visited[co] ){
        visited[co] = true;
        memo[co] = memo[tope]+1;
        q.push(co);
      }
    }
  }
}

int main() {
	//FAST_IO;
  int P, N, cases, i, scenario = 0, j, k;
  string line;

  scanf("%d\n", &cases);

  while(cases--){
    scanf("%d %d\n", &P, &N);

    map<string, vs> authors;
    scenario++;

    fl(i, 0, P){
      getline(cin, line);

      //Parse input
      vs parse = parseInput(line);
      parse.pop_back();
      //string book = parse[len(parse)-1];

      fl(j, 0, len(parse)-1){
        fl(k, j+1, len(parse)){
          authors[parse[j]].pb(parse[k]);
          authors[parse[k]].pb(parse[j]);
        }
      }
    }
    map<string, int> memo;
    solve(authors, memo, "Erdos, P.");

    cout << "Scenario " << scenario << endl;

    fl(i, 0, N){
      getline(cin, line);
      if(memo.find(line) == memo.end()){
        cout << line << " infinity" << endl;
      }
      else
        cout << line << " " << memo[line] << endl;
    }
  }

	return 0;
}

