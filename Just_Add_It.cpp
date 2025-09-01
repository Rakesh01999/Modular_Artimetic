#include <bits/stdc++.h>
using namespace std;

const long long MOD = 10000007;

long long modpow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;

        long long t1 = (2 * modpow(n - 1, k)) % MOD;
        long long t2 = modpow(n, k);
        long long t3 = (2 * modpow(n - 1, n - 1)) % MOD;
        long long t4 = modpow(n, n);

        long long ans = (t1 + t2) % MOD;
        ans = (ans + t3) % MOD;
        ans = (ans + t4) % MOD;

        cout << ans % MOD << "\n";
    }
    return 0;
}
