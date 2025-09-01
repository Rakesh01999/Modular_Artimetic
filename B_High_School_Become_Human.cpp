#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y;
    cin >> x >> y;

    if (x == y) {
        cout << "=" << "\n";
        return 0;
    }

    long double left = (long double) y * log((long double) x);
    long double right = (long double) x * log((long double) y);

    if (fabsl(left - right) < 1e-12) {
        cout << "=" << "\n";
    } else if (left < right) {
        cout << "<" << "\n";
    } else {
        cout << ">" << "\n";
    }

    return 0;
}
