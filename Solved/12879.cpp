/*
 *
 * UVa 12879 - Golf Bot
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

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
  int n = a.size();

  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;

    if (i < j) swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }

  if (invert) {
    for (cd& x : a) x /= n;
  }
}

vector<long long> multiply(vector<long long> const& a,
                           vector<long long> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;

  while (n < a.size() + b.size()) n <<= 1;

  fa.resize(n);
  fb.resize(n);

  fft(fa, false);
  fft(fb, false);

  for (int i = 0; i < n; i++) fa[i] *= fb[i];

  fft(fa, true);

  vector<long long> result(n);

  for (int i = 0; i < n; i++) result[i] = round(fa[i].real());

  return result;
}

int main() {
  FAST_IO;

  int N, M, ans;
  ll a;

  vi nums, holes;

  while (cin >> N) {
    ans = 0;
    nums = vi(N);

    for (int& x : nums) cin >> x;

    cin >> M;

    holes = vi(M);
    for (int& x : holes) cin >> x;

    int max_size = 1;

    for (int& x : nums) max_size = max(x, max_size);

    vll p(max_size + 1, 0);

    for (int& x : nums) p[x] = 1;

    vll q(p);

    q[0] = 1;

    vll result = multiply(p, q);

    for (int& x : holes)
      if (result[x] and x <= 2 * max_size) ans++;

    cout << ans << endl;
  }

  return 0;
}