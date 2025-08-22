#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const unsigned long long MOD = 109546051211ULL;
    int n;
    cin >> n;

    unsigned long long fact = 1, ans = 1;
    for (int i = 1; i <= n; ++i) {
        fact = ((__uint128_t)fact * i) % MOD;
        ans  = ((__uint128_t)ans  * fact) % MOD;
    }

    // Convert __uint128_t to string manually
    string output;
    __uint128_t final = ans;
    if (final == 0) output = "0";
    else {
        while (final > 0) {
            output = char('0' + final % 10) + output;
            final /= 10;
        }
    }

    cout << output << '\n';
    return 0;
}
