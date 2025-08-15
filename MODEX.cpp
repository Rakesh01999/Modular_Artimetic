#include <iostream>
using namespace std;

int modExpo(int x, int y, int n) {
    long long result = 1;
    long long base = x % n;

    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * base) % n;
        }
        base = (base * base) % n;
        y /= 2;
    }

    return result;
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        int x, y, n;
        cin >> x >> y >> n;
        cout << modExpo(x, y, n) << endl;
    }

    int endSignal;
    cin >> endSignal; // Read the final '0' line
    return 0;
}
