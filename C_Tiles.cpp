#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// Fast exponentiation
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h;
    cin >> w >> h;

    cout << mod_pow(2, w + h, MOD) << '\n';
    return 0;
}

