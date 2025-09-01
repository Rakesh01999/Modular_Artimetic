#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

int fact[MAXN], inv_fact[MAXN];


int mod_pow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1LL * res * x % MOD;
        x = 1LL * x * x % MOD;
        y >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
        inv_fact[i] = mod_pow(fact[i], MOD - 2);
    }
}

bool is_good(int x, int a, int b) {
    while (x) {
        int d = x % 10;
        if (d != a && d != b) return false;
        x /= 10;
    }
    return true;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    precompute();
    int result = 0;

    for (int i = 0; i <= n; ++i) {
        int sum = i * a + (n - i) * b;
        if (is_good(sum, a, b)) {
            int comb = 1LL * fact[n] * inv_fact[i] % MOD * inv_fact[n - i] % MOD;
            result = (result + comb) % MOD;
        }
    }

    cout << result << endl;
    return 0;
}
