#include <iostream>
using namespace std;

const long long MOD = 109546051211;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long result = 1;
    long long fact = 1;

    for (int i = 1; i <= n; ++i) {
        fact = (fact * i) % MOD;       // Compute i! modulo MOD
        result = (result * fact) % MOD; // Multiply into the product

        // Early termination: once factorial becomes 0 mod MOD, all future products are 0
        if (fact == 0) break;
    }

    cout << result << '\n';
    return 0;
}
