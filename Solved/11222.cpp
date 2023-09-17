/*
 *
 * UVa 11222 - Only I did it!
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

int main() {
    FAST_IO;
    int t, s, n, cases = 0;

    cin >> t;

    while (t--) {
        cases++;
        vi cnt(10000, 0);
        vvi ans(3, vi(0));

        cin >> s;
        fl(i, 0, s) {
            cin >> n;
            n--;
            if (cnt[n] == 0 or cnt[n] == 1)
                cnt[n] = 1;
            else
                cnt[n] = -1;
        }

        cin >> s;
        fl(i, 0, s) {
            cin >> n;
            n--;
            if (cnt[n] == 0 or cnt[n] == 2)
                cnt[n] = 2;
            else
                cnt[n] = -1;
        }

        cin >> s;
        fl(i, 0, s) {
            cin >> n;
            n--;
            if (cnt[n] == 0 or cnt[n] == 5)
                cnt[n] = 5;
            else
                cnt[n] = -1;
        }

        fl(i, 0, len(cnt)) {
            if (cnt[i] == 1)
                ans[0].pb(i + 1);
            else if (cnt[i] == 2)
                ans[1].pb(i + 1);
            else if (cnt[i] == 5)
                ans[2].pb(i + 1);
        }

        int max_size = max(len(ans[0]), max(len(ans[1]), len(ans[2])));

        cout << "Case #" << cases << ":" << endl;
        fl(i, 0, 3) {
            if (len(ans[i]) == max_size) {
                cout << i + 1 << " " << len(ans[i]);
                for (int &x : ans[i]) cout << " " << x;
                cout << endl;
            }
        }
    }

    return 0;
}
