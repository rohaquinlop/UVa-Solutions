/*
 *
 * UVa 897 - Anagrammatic Primes
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
bitset<10000010> is_ana(0);
vll ana;
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

bool isPrime(ll N) {
    if (N < _sieve_size) return bs[N];
    for (int i = 0; i < len(p) and p[i] * p[i] <= N; i++)
        if (N % p[i] == 0) return false;
    return true;
}

void init_ana() {
    string s;
    bool flag;
    for (ll prime : p) {
        // trace1(prime);
        s = to_string(prime);
        srt(s);
        vll temp;
        flag = true;

        do {
            ll t = stoll(s, nullptr, 10);
            if (isPrime(t)) {
                temp.pb(t);
            } else {
                flag = false;
            }
        } while (next_permutation(all(s)) and flag);

        if (flag) {
            for (ll &t : temp) {
                if (!is_ana[t]) {
                    ana.pb(t);
                    is_ana[t] = 1;
                }
            }
        }
    }
}

ll bin_expo(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 0) {
        ll tmp = bin_expo(a, b / 2);
        return tmp * tmp;
    } else {
        ll tmp = bin_expo(a, (b - 1) / 2);
        return a * tmp * tmp;
    }
}

int main() {
    FAST_IO;
    // sieve(10000000);
    // init_ana();

    // srt(ana);

    ana = {2,  3,  5,   7,   11,  13,  17,  31,  37,  71,  73,
           79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};
    ll n, ans;

    while (cin >> n and n != 0) {
        auto it = upper_bound(all(ana), n);
        ll cnt_digits = floor(log10(n)) + 1;
        ll t_limit = bin_expo(10, cnt_digits);
        if (it != ana.end() and *it < t_limit)
            cout << *it << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}