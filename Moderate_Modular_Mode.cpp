#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        long long n;
        if (y < x) {
            n = x + y;
        } else {
            long long r = y % x;          
            n = y - r / 2;                
        }

        cout << n << '\n';
    }
    return 0;
}
