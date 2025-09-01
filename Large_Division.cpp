#include <bits/stdc++.h>
using namespace std;

// Function to compute (a % b) where a is a string (possibly very large)
long long modString(const string &a, long long b) {
    long long rem = 0;
    for (char ch : a) {
        if (ch == '-') continue;  // ignore negative sign
        int digit = ch - '0';
        rem = (rem * 10 + digit) % b;
    }
    return rem;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        string a;
        long long b;
        cin >> a >> b;

        long long rem = modString(a, abs(b));  // work with |b|
        cout << "Case " << tc << ": ";
        if (rem == 0)
            cout << "divisible\n";
        else
            cout << "not divisible\n";
    }

    return 0;
}
