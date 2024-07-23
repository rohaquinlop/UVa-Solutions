/*
 *
 * UVa 11749 - Poor Trade Advisor
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

int dfs(vector<vpii>& graph, vector<int>& visited, int node, int ppa,
        int cities) {
    fl(i, 0, len(graph[node])) {
        if (graph[node][i].fr == ppa and !visited[graph[node][i].sc]) {
            visited[graph[node][i].sc] = 1;
            cities += dfs(graph, visited, graph[node][i].sc, ppa, 1);
        }
    }

    return cities;
}

int main() {
    FAST_IO;
    int n, m;
    int u, v, p, tmp, lst_ppa;

    while (cin >> n >> m and n and m) {
        vector<vpii> graph(n);
        priority_queue<pair<int, pii>> pq;
        pii ans = {0, 0};

        fl(i, 0, m) {
            cin >> u >> v >> p;
            u--, v--;
            graph[u].pb({p, v});
            graph[v].pb({p, u});

            pq.push({p, {u, v}});
        }

        vi visited(n, 0);
        lst_ppa = pq.top().fr;

        while (!pq.empty() and pq.top().fr == lst_ppa) {
            p = pq.top().fr;
            u = pq.top().sc.fr;
            v = pq.top().sc.sc;

            pq.pop();

            if (!visited[u]) {
                visited[u] = 1;
                tmp = dfs(graph, visited, u, p, 1);

                if (ans.sc == 0 or ans.fr < p)
                    ans = {p, tmp};
                else if (ans.fr == p)
                    ans.sc = max(ans.sc, tmp);
            }

            lst_ppa = p;
        }

        cout << ans.sc << endl;
    }

    return 0;
}