#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    long long result = 1;
    for (long long i = 1; i <= n; i++) {
        result = (result * i) % MOD;
    }

    cout << result << "\n";
    return 0;
}
