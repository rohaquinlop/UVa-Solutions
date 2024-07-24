/*
 *
 * UVa 11906 - Knight in War Grid
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
    int T, R, C, M, N, W;
    int r, c, row, column, squares, even, odd, cases = 0;

    cin >> T;

    while (T--) {
        cin >> R >> C >> M >> N >> W;
        cases++;

        vvi grid(R, vi(C, 1));

        fl(i, 0, W) {
            cin >> r >> c;
            grid[r][c] = 0;
        }

        queue<pii> q;
        vvi visited(R, vi(C, 0));

        q.push({0, 0});
        visited[0][0]++;
        even = odd = 0;
        int turn = 1;

        while (!q.empty()) {
            row = q.front().fr;
            column = q.front().sc;
            q.pop();
            turn++;

            squares = 0;

            r = row + M;
            c = column + N;

            if (r >= 0 and r < R and c >= 0 and c < C and grid[r][c] != 0 and
                grid[r][c] != turn) {
                squares++;
                grid[r][c] = turn;
                if (!visited[r][c]) {
                    visited[r][c]++;
                    q.push({r, c});
                }
            }

            r = row + M;
            c = column - N;

            if (r >= 0 and r < R and c >= 0 and c < C and grid[r][c] != 0 and
                grid[r][c] != turn) {
                squares++;
                grid[r][c] = turn;
                if (!visited[r][c]) {
                    visited[r][c]++;
                    q.push({r, c});
                }
            }

            r = row - M;
            c = column + N;

            if (r >= 0 and r < R and c >= 0 and c < C and grid[r][c] != 0 and
                grid[r][c] != turn) {
                squares++;
                grid[r][c] = turn;
                if (!visited[r][c]) {
                    visited[r][c]++;
                    q.push({r, c});
                }
            }

            r = row - M;
            c = column - N;

            if (r >= 0 and r < R and c >= 0 and c < C and grid[r][c] != 0 and
                grid[r][c] != turn) {
                squares++;
                grid[r][c] = turn;
                if (!visited[r][c]) {
                    visited[r][c]++;
                    q.push({r, c});
                }
            }

            r = row + N;
            c = column + M;

            if (r >= 0 and r < R and c >= 0 and c < C and grid[r][c] != 0 and
                grid[r][c] != turn) {
                squares++;
                grid[r][c] = turn;
                if (!visited[r][c]) {
                    visited[r][c]++;
                    q.push({r, c});
                }
            }

            r = row + N;
            c = column - M;

            if (r >= 0 and r < R and c >= 0 and c < C and grid[r][c] != 0 and
                grid[r][c] != turn) {
                squares++;
                grid[r][c] = turn;
                if (!visited[r][c]) {
                    visited[r][c]++;
                    q.push({r, c});
                }
            }

            r = row - N;
            c = column + M;

            if (r >= 0 and r < R and c >= 0 and c < C and grid[r][c] != 0 and
                grid[r][c] != turn) {
                squares++;
                grid[r][c] = turn;
                if (!visited[r][c]) {
                    visited[r][c]++;
                    q.push({r, c});
                }
            }

            r = row - N;
            c = column - M;

            if (r >= 0 and r < R and c >= 0 and c < C and grid[r][c] != 0 and
                grid[r][c] != turn) {
                squares++;
                grid[r][c] = turn;
                if (!visited[r][c]) {
                    visited[r][c]++;
                    q.push({r, c});
                }
            }

            if (squares % 2 == 0)
                even++;
            else
                odd++;
        }

        cout << "Case " << cases << ": " << even << " " << odd << endl;
    }

    return 0;
}