/*
 *
 * UVa 10993 - Ignoring Digits
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

    string f;
    int n, mod, new_mod;

    while (cin >> f >> n and f != "0" and n) {
        set<char> valid_digits;

        for (char& c : f) {
            valid_digits.insert(c);
        }

        vi visited(n, 0);

        queue<pair<string, int>> q;
        pair<string, int> actual_state;
        string ans = "impossible";

        for (auto x : valid_digits) {
            if (x != '0') {
                string s = "";
                s.push_back(x);
                q.push({s, (x - '0') % n});
                visited[(x - '0') % n]++;
            }
        }

        while (!q.empty() and ans == "impossible") {
            actual_state = q.front();
            q.pop();

            mod = actual_state.second;

            if (mod % n == 0) ans = actual_state.first;

            for (auto x : valid_digits) {
                new_mod = (((mod * 10) % n) + ((x - '0') % n)) % n;
                if (!visited[new_mod]) {
                    string new_string = actual_state.first;
                    new_string.push_back(x);
                    q.push({new_string, new_mod});
                    visited[new_mod]++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}