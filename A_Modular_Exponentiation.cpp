#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    if (n >= 31) {
        cout << m << "\n";  // 2^n > m, so remainder = m
    } else {
        long long modVal = 1LL << n;  // compute 2^n
        cout << m % modVal << "\n";
    }

    return 0;
}
