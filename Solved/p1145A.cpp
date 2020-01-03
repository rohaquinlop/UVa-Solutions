/*
*
* Problema Codeforces 1145A - Thanos Sort
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

#define fl(i, a, b)	for (int i(a); i < (b); ++ i)

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

int maxL;

bool isOrdered(vi &nums){
	if( nums.size() == 1 ){
		return true;
	}
	else{
		for(int i = 0; i < nums.size()-1; i++){
			if( nums[i] > nums[i+1] )
				return false;
		}
		return true;
	}
}

vector<int> firstPartVector(vi nums){
	vi res;
	for(int i = 0; i < (nums.size())/2; i++)
		res.pb( nums[i] );
	return res;
}

vector<int> secondPartVector(vi nums){
	vi res;
	for(int i = (nums.size())/2; i < nums.size(); i++)
		res.pb( nums[i] );
	return res;
}

void backTrack(vi nums){
	if( maxL >= nums.size() )
		return;
	if( isOrdered(nums) ){
		if( nums.size() > maxL )
			maxL = nums.size();
		return;
	}
	else{
		backTrack( firstPartVector(nums) );
		backTrack (secondPartVector(nums) );
	}
}

int main() {
	FAST_IO;

	int n, i, aux;

	while( cin >> n ){
		vi nums;
		maxL = 0;
		for(i = 0; i < n; i++){
			cin >> aux;
			nums.pb(aux);
		}
		backTrack(nums);

		cout << maxL << endl;
	}


	return 0;
}