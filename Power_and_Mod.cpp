#include <bits/stdc++.h>
using namespace std;

// parse decimal string into unsigned __int128
unsigned __int128 parse_u128(const string &s) {
    unsigned __int128 x = 0;
    for (char c : s) {
        if (c < '0' || c > '9') continue;
        x = x * 10 + (c - '0');
    }
    return x;
}

// print unsigned __int128 as decimal
string to_string_u128(unsigned __int128 x) {
    if (x == 0) return "0";
    string out;
    while (x > 0) {
        unsigned int digit = (unsigned int)(x % 10);
        out.push_back(char('0' + digit));
        x /= 10;
    }
    reverse(out.begin(), out.end());
    return out;
}

// modular multiplication (a*b) % m using unsigned __int128 (safe for m <= 2^64)
static inline unsigned __int128 mulmod_u128(unsigned __int128 a, unsigned __int128 b, unsigned __int128 m) {
    // Using direct product is safe because a < m, b < m, and m <= 2^64 => a*b < 2^128
    return (a * b) % m;
}

// modular exponentiation: a^e % m, where a and m are unsigned __int128, e is unsigned long long
unsigned __int128 modexp_u128(unsigned __int128 a, unsigned long long e, unsigned __int128 m) {
    if (m == 1) return 0;
    unsigned __int128 res = 1 % m;
    a %= m;
    while (e) {
        if (e & 1ULL) res = mulmod_u128(res, a, m);
        a = mulmod_u128(a, a, m);
        e >>= 1ULL;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        unsigned long long a, b;
        string mstr;
        cin >> a >> b >> mstr;

        // parse m into 128-bit
        unsigned __int128 M = parse_u128(mstr);
        if (M == 0) { // not expected per statement, but guard
            cout << "0\n";
            continue;
        }

        // compute a^b % M
        unsigned __int128 base = (unsigned __int128)a % M;
        unsigned __int128 ans = modexp_u128(base, b, M);

        cout << to_string_u128(ans) << '\n';
    }
    return 0;
}
