#include <bits/stdc++.h>
using namespace std;
const long long MOD = 10000007;

// Function to do (a * b) % mod safely without overflow
long long modMul(long long a, long long b, long long mod) {
    long long res = 0;
    a %= mod;
    while (b > 0) {
        if (b & 1) { // if b is odd
            res = (res + a) % mod;
        }
        a = (a * 2) % mod;
        b >>= 1; // divide b by 2
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    int caseNo = 1;
    while (cin >> a >> b) {
        long long ans = modMul(a, b, MOD);
        cout << "Case #" << caseNo++ << ": " << ans << "\n";
    }
    return 0;
}
