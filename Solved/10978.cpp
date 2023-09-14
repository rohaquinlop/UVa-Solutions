/*
 *
 * UVa 10978 - Let’s Play Magic!
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

int insert_card(vs& v, int insert_pos, int word_len, string& s) {
    if (v[insert_pos] != "") {
        return insert_card(v, (insert_pos + 1) % len(v), word_len, s);
    } else if (word_len == 1 and v[insert_pos] == "") {
        v[insert_pos] = s;
        return insert_pos;
    } else {
        return insert_card(v, (insert_pos + 1) % len(v), word_len - 1, s);
    }
}

int main() {
    FAST_IO;
    int n, lst_pos;
    string s1, s2;

    while (cin >> n and n) {
        vs v(n, "");
        lst_pos = 0;

        for (int i = 0; i < n; i++) {
            cin >> s1 >> s2;
            lst_pos = insert_card(v, lst_pos == 0 ? 0 : (lst_pos + 1) % n,
                                  len(s2), s1);
        }

        for (int i = 0; i < n; i++) {
            cout << v[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}