#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

long long fact[MAXN], invFact[MAXN];

// Fast exponentiation modulo MOD
long long modpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// Check if a number only contains digits a or b
bool isGood(int x, int a, int b) {
    while (x > 0) {
        int d = x % 10;
        if (d != a && d != b) return false;
        x /= 10;
    }
    return true;
}

// Compute nCk modulo MOD
long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n;
    cin >> a >> b >> n;

    // Precompute factorials and inverses
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[n] = modpow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;

    long long ans = 0;
    for (int k = 0; k <= n; ++k) {
        int sum = k * a + (n - k) * b;
        if (isGood(sum, a, b)) {
            ans = (ans + C(n, k)) % MOD;
        }
    }
    cout << ans << "\n";
}
