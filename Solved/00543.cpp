/*
 *
 * UVa 543 - Goldbach's Conjecture
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
#define trace3(x1, x2, x3)                                                \
  cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 \
       << ": " << x3 << endl;

#define FAST_IO                     \
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

int main() {
  FAST_IO;
  ll n, a, b;

  sieve(1000000);

  while (cin >> n and n != 0) {
    a = 0, b = 0;
    for (int i = 0; i < len(p) and p[i] < n and a == 0 and b == 0; i++) {
      if (bs[n - p[i]]) {
        a = p[i];
        b = n - p[i];
      }
    }

    if (a != 0 and b != 0)
      cout << n << " = " << a << " + " << b << endl;
    else
      cout << "Goldbach's conjecture is wrong." << endl;
  }

  return 0;
}