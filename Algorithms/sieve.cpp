#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define pb push_back

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

bool isPrime(ll N) {
    if (N < _sieve_size) return bs[N];
    for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; i++) {
        if (N % p[i] == 0) return false;
    }
    return true;
}

// Linear sieve
const int M = 10000000;  // 10^7
vector<int> lp(M + 1);
vector<int> pr;

void linear_sieve() {
    for (int i = 2; i <= M; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= M; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}
