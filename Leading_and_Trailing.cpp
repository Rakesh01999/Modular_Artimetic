#include <bits/stdc++.h>
using namespace std;

// Function for modular exponentiation (last 3 digits)
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long n, k;
        cin >> n >> k;

        // Last 3 digits
        long long last = mod_exp(n, k, 1000);

        // First 3 digits
        double x = k * log10(n);
        double fractional = x - floor(x);
        double leading = pow(10, fractional + 2); // shift for 3 digits
        int first = (int)leading;

        // Format last 3 digits with leading zeros if necessary
        cout << first << "...";
        cout << setw(3) << setfill('0') << last << "\n";
    }
    return 0;
}
