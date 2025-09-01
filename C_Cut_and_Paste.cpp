#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int x;
        string s;
        cin >> x >> s;

        long long len = (long long)s.size();

        for (int i = 0; i < x; ++i) {
            int d = s[i] - '0';                 // guaranteed to exist by problem statement

            // len_new = (i+1) + d * (len_old - (i+1))
            long long tail = ( (len - (i + 1)) % MOD + MOD ) % MOD;
            len = ( (i + 1) + (tail * d) % MOD ) % MOD;

            // Physically expand s only up to x characters so we can read s[i] later
            if ((int)s.size() < x) {
                string add = s.substr(i + 1);
                for (int rep = 1; rep < d && (int)s.size() < x; ++rep) {
                    s += add;
                }
                if ((int)s.size() > x) s.resize(x);
            }
        }
        cout << (len % MOD + MOD) % MOD << '\n';
    }
    return 0;
}
