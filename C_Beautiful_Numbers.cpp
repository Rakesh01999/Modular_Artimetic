#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long modpow(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// Precompute factorials and inverses
vector<long long> fact, invFact;
void initFactorials(int n) {
    fact.resize(n+1);
    invFact.resize(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % MOD;
    invFact[n] = modpow(fact[n], MOD-2, MOD);
    for (int i = n-1; i >= 0; i--) invFact[i] = (invFact[i+1] * (i+1)) % MOD;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
}

// Check if number is "good"
bool isGood(long long x, int a, int b) {
    while (x > 0) {
        int d = x % 10;
        if (d != a && d != b) return false;
        x /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n;
    cin >> a >> b >> n;

    initFactorials(n);

    long long ans = 0;
    for (int k = 0; k <= n; k++) {
        long long sum = 1LL * k * a + 1LL * (n - k) * b;
        if (isGood(sum, a, b)) {
            ans = (ans + nCr(n, k)) % MOD;
        }
    }

    cout << ans % MOD << "\n";
    return 0;
}
