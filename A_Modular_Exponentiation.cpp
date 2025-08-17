#include <iostream>
using namespace std;

int main() {
    int n;
    unsigned int m;
    cin >> n >> m;

    if (n >= 31) {
        // 2^31 > 10^9, so m < 2^n
        cout << m << endl;
    } else {
        unsigned int power = 1U << n; // 2^n using bit shift
        cout << m % power << endl;
    }

    return 0;
}
