/*
 *
 * UVa 13303 - kewl Texting
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

vi split_string(string& line, map<string, int>& word_id, vs& id_word, int& id) {
    vi v;
    string s;
    stringstream ss(line);

    v.pb(0);

    while (ss >> s) {
        if (word_id.count(s) == 0) {
            word_id[s] = id;
            id_word[id] = s;
            v.pb(id++);
        } else {
            v.pb(word_id[s]);
        }
    }

    v.pb(1);

    return v;
}

bool compare(pair<int, pair<int, pair<int, string>>>& a,
             pair<int, pair<int, pair<int, string>>>& b) {
    if (a.first == b.first) {
        if (a.second.first == b.second.first)
            return a.second.second.second < b.second.second.second;
        return a.second.first > b.second.first;
    }
    return a.first > b.first;
}

int next_id(vector<pair<int, pair<int, pair<int, string>>>>& v) {
    pair<int, pair<int, pair<int, string>>> t = v[0];

    for (pair<int, pair<int, pair<int, string>>>& p : v)
        if (compare(p, t)) t = p;

    return t.second.second.first;
}

int main() {
    FAST_IO;
    int n, id;
    string line, s;

    while (cin >> n) {
        cin.ignore();
        map<int, map<int, int>> connections;
        map<string, int> word_id;
        vs id_word(1e5 + 2);
        vi cnt(1e5 + 2, 0);
        id = 2;

        word_id["A"] = 0;
        id_word[0] = "A";

        word_id["B"] = 1;
        id_word[1] = "B";

        fl(i, 0, n) {
            getline(cin, line);
            vi v = split_string(line, word_id, id_word, id);

            cnt[1]++;

            fl(j, 0, len(v) - 1) {
                cnt[v[j]]++;
                connections[v[j]][v[j + 1]]++;
            }
        }

        int actual = 0;
        string ans = "";
        bool found_cycle = false;
        vi visited(1e5 + 2, 0);

        while (!found_cycle) {
            vector<pair<int, pair<int, pair<int, string>>>> v;
            visited[actual]++;

            for (auto& p : connections[actual]) {
                v.push_back(
                    {p.second, {cnt[p.first], {p.first, id_word[p.first]}}});
            }

            actual = next_id(v);

            if (visited[actual])
                found_cycle = true;
            else if (actual == 1)
                break;
            else {
                if (len(ans)) ans.pb(' ');
                ans += id_word[actual];
            }
        }

        if (found_cycle)
            cout << "INFINITE" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
