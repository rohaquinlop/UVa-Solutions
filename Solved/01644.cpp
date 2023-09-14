/*
 *
 * UVa 1644 - Prime Gap
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

// Sieve

ll _sieve_size;
bitset<10000010> bs;
vll p;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < _sieve_size; i++)
        if (bs[i]) {
            for (ll j = i * i; j < _sieve_size; j += i) bs[j] = 0;
            p.pb(i);
        }
}

vector<pair<ll, ll>> prime_gap;

int binary_search(vector<pair<ll, ll>>& prime_gap, ll value) {
    int lo = 0, hi = len(prime_gap), mid;

    while (lo + 1 < hi) {
        mid = lo + ((hi - lo) >> 1);

        if (value >= prime_gap[mid].first and value <= prime_gap[mid].second) {
            return mid;
        } else if (value > prime_gap[mid].second)
            lo = mid;
        else
            hi = mid;
    }

    return -1;
}

int main() {
    FAST_IO;
    ll k;
    int pos;

    sieve(1299709);

    prime_gap.pb({0, 1});

    for (int i = 0; i < len(p) - 1; i++) {
        if (p[i + 1] - p[i] > 1) {
            prime_gap.pb({p[i] + 1, p[i + 1] - 1});
        }
    }

    while (cin >> k and k) {
        pos = binary_search(prime_gap, k);

        if (pos == -1)
            cout << 0 << endl;
        else
            cout << prime_gap[pos].second - prime_gap[pos].first + 2 << endl;
    }

    return 0;
}