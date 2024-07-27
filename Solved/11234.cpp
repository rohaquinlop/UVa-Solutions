/*
 *
 * UVa
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

pair<string, pair<string, string>> get_node(string& str) {
    int n = len(str) - 1, counter = 1, i = len(str) - 2;
    string parent = "";
    parent += str[n];

    if (str[n] >= 'a' and str[n] <= 'z') {
        return {parent, {"", ""}};
    }

    while (counter > 0) {
        if (str[i] >= 'A' and str[i] <= 'Z') counter += 2;

        counter--;
        i--;
    }

    return {parent, {str.substr(i + 1, n - (i + 1)), str.substr(0, i + 1)}};
}

void solve(string& str, map<int, vs>& lvl_dict, int lvl) {
    string parent, left, right;

    if (len(str) == 1) {
        lvl_dict[lvl].pb(str);
        return;
    }

    pair<string, pair<string, string>> p = get_node(str);

    parent = p.fr;
    left = p.sc.fr;
    right = p.sc.sc;

    lvl_dict[lvl].pb(parent);

    solve(left, lvl_dict, lvl + 1);
    solve(right, lvl_dict, lvl + 1);
}

int main() {
    FAST_IO;
    int T;
    string str;

    cin >> T;

    while (T--) {
        cin >> str;
        string ans;

        map<int, vs> lvl_dict;

        solve(str, lvl_dict, 0);

        for (int i = len(lvl_dict) - 1; i >= 0; i--)
            fl(j, 0, len(lvl_dict[i])) ans += lvl_dict[i][j];

        cout << ans << endl;
    }

    return 0;
}