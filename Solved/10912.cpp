/*
 *
 * UVa 10912 - Simple Minded Hashing
 *
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define fl(i, a, b) for (int i = a; i < b; ++i)

#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))

#define pb push_back
#define mp make_pair

#define dig(i) (s[i] - '0')
#define slen(s) s.length()

#define fr first
#define sc second

#define len(x) x.size()
#define fill(x, y) memset(x, y, sizeof(x))
#define clr(a) fill(a, 0)
#define endl '\n'

#define PI 3.14159265358979323

#define trace1(x1) cerr << #x1 << ": " << x1 << endl;
#define trace2(x1, x2) \
    cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << endl;
#define trace3(x1, x2, x3)                                                  \
    cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 \
         << ": " << x3 << endl;

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
template <typename T>
T power(T x, T y, ll m = MOD) {
    T ans = 1;
    x %= m;
    while (y > 0) {
        if (y & 1ll) ans = (ans * x) % m;
        y >>= 1ll;
        x = (x * x) % m;
    }
    return ans % m;
}

int solve(int i, int l, int s, vector<vvi> &memo) {
    int ans;

    if (memo[i][l][s] != -1) return memo[i][l][s];

    if (s == 0 or i == 27) {
        ans = 0;
        if (l == 0) ans = !s;
    } else {
        ans = solve(i + 1, l, s, memo);
        if (l and s - i >= 0) ans += solve(i + 1, l - 1, s - i, memo);
    }

    memo[i][l][s] = ans;

    return ans;
}

int main() {
    FAST_IO;
    int L, S, counter = 0, ans, cal;

    while (cin >> L >> S and L and S) {
        ans = 0;
        cal = 351 - (((L - 27) * (L - 26)) / 2);
        vector<vvi> memo(30, vvi(30, vi(360, -1)));

        if (S <= cal and L <= 26) {
            ans = solve(1, L, S, memo);
        }

        cout << "Case " << ++counter << ": " << ans << endl;
    }

    return 0;
}