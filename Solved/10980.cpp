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

double solve(int &k, int total_elements, vector<pair<double, int>> &products,
             double unit_price, vector<double> &memo) {
    if (memo[total_elements] != -1) return memo[total_elements];
    if (total_elements >= k) return 0;

    double ans =
        solve(k, total_elements + 1, products, unit_price, memo) + unit_price;

    fl(i, 0, len(products)) {
        ans = min(ans, solve(k, total_elements + products[i].sc, products,
                             unit_price, memo) +
                           products[i].fr);
    }

    memo[total_elements] = ans;

    return ans;
}

int main() {
    // FAST_IO;
    double f, p, a;
    int M, N, b, n, c = 0;
    string line;
    double ans;

    while (scanf("%lf %d\n", &f, &M) == 2) {
        vector<pair<double, int>> v;
        vi nums;

        fl(i, 0, M) {
            scanf("%d %lf\n", &b, &a);
            v.pb({a, b});
        }

        getline(cin, line);
        stringstream ss(line);

        while (ss >> n) nums.pb(n);

        cout << "Case " << ++c << ":" << endl;
        fl(i, 0, len(nums)) {
            vector<double> memo(201, -1);
            ans = solve(nums[i], 0, v, f, memo);
            printf("Buy %d for $%.2lf\n", nums[i], ans);
        }
    }

    return 0;
}