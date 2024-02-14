/*
 *
 * UVa 10858 - Unique Factorization
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
vll primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < _sieve_size; i++)
        if (bs[i]) {
            for (ll j = i * i; j < _sieve_size; j += i) bs[j] = 0;
            primes.pb(i);
        }
}

vll trial_division4(ll n) {
    vll factorization;
    for (ll d : primes) {
        if (d * d > n) break;
        while (n % d == 0) {
            factorization.pb(d);
            n /= d;
        }
    }

    if (n > 1) factorization.pb(n);
    return factorization;
}

vvll solve(vll &factorization) {
    ll frst;
    vvll ans;
    queue<vll> q;
    map<vll, bool> visited;

    ans.pb(factorization);
    q.push(factorization);

    while (!q.empty()) {
        vll current = q.front();
        q.pop();

        if (len(current) > 1) {
            fl(i, 0, len(current) - 1) {
                fl(j, i + 1, len(current)) {
                    vll new_factorization = current;
                    new_factorization[i] *= current[j];
                    new_factorization.erase(new_factorization.begin() + j);
                    srt(new_factorization);
                    if (!visited[new_factorization] and
                        len(new_factorization) > 1) {
                        visited[new_factorization] = true;
                        q.push(new_factorization);
                        ans.pb(new_factorization);
                    }
                }
            }
        }
    }

    srt(ans);

    return ans;
}

int main() {
    FAST_IO;

    ll n;
    vll factorization;
    vvll ans;

    sieve(2000000);

    while (cin >> n and n) {
        factorization = trial_division4(n);
        srt(factorization);
        ans = solve(factorization);

        if (len(ans) == 1 and (len(ans[0]) == 1 or len(ans[0]) == 0)) {
            cout << 0 << endl;
        } else {
            cout << len(ans) << endl;
            for (vll &v : ans) {
                fl(i, 0, len(v)) {
                    cout << v[i];
                    if (i < len(v) - 1) cout << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}