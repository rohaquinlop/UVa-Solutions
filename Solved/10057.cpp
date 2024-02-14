/*
 *
 * UVa 10057 - A mid-summer night's dream
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

void solve(vi& cnt, int highest, int n) {
    int accum = 0;
    if (n % 2 != 0) {
        fl(i, 0, highest + 1) {
            accum += cnt[i];
            if (accum > n / 2) {
                cout << i << " " << cnt[i] << " " << 1 << endl;
                return;
            }
        }
    }
    int low_median = 0, high_median = 0;

    fl(i, 0, highest + 1) {
        accum += cnt[i];
        if (accum >= n / 2) {
            low_median = i;
            break;
        }
    }
    accum = 0;
    fl(i, 0, highest + 1) {
        accum += cnt[i];
        if (accum >= n / 2 + 1) {
            high_median = i;
            break;
        }
    }

    if (low_median == high_median) {
        cout << low_median << " " << cnt[low_median] << " " << 1 << endl;
    } else {
        cout << low_median << " " << cnt[low_median] + cnt[high_median] << " "
             << high_median - low_median + 1 << endl;
    }
}

int main() {
    FAST_IO;
    int n, highest;

    while (cin >> n) {
        vi cnt(65536 + 1, 0);
        highest = 0;

        fl(i, 0, n) {
            int x;
            cin >> x;
            cnt[x]++;
            highest = max(highest, x);
        }

        solve(cnt, highest, n);
    }

    return 0;
}
