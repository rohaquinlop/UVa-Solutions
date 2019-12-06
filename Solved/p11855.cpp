/*
*
* Problema UVa 11855 - Buzzwords
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

vector<int> count_unique_substrings(string const& s) {
    int n = s.size();

    const int p = 53;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'A' + 1) * p_pow[i]) % m;

    vector<int> vals;
    for (int l = 1; l <= n; l++) {
    	vector<int> hs;
    	map<long long, int> can;
    	int accum = 1;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            if( find(hs.begin(), hs.end(), cur_h) != hs.end() ){
            	int internalVal = can[cur_h];
            	can[cur_h] = internalVal+1;
            	if( internalVal+1 > accum )
            		accum = internalVal+1;
            }
            else
            	can[cur_h] = 1;
            hs.push_back(cur_h);
        }
        if( accum == 1 )
        	break;
        vals.push_back(accum);
    }

    return vals;
}

int main() {
	FAST_IO;

    int c = 0, i;
	string line, subString;

	while( getline(cin, line) ){

		if( line != "" ){
			line.erase(remove(line.begin(), line.end(), ' '), line.end());
			c++;
			subString = "";

			vector<int> res = count_unique_substrings(line);

			for(int i : res){
				printf("%d\n", i);
			}
			printf("\n");
		}
	}


	return 0;
}