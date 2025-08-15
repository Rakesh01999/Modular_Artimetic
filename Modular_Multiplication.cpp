#include <iostream>
using namespace std;

const long long MOD = 10000007;

int main() {
    long long a, b;
    int caseNum = 1;
    while (cin >> a >> b) {
        long long result = (a % MOD) * (b % MOD) % MOD;
        cout << "Case #" << caseNum++ << ": " << result << endl;
    }
    return 0;
}
