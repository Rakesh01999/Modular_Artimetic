#include <iostream>
using namespace std;

long long modExpo(long long b, long long p, long long m)
{
    long long result = 1;
    long long base = b % m;

    while (p > 0)
    {
        if (p % 2 == 1)
        {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        p /= 2;
    }

    return result;
}

int main()
{

    long long b, p, m;
    while (cin >> b >> p >> m)
    {
        cout << modExpo(b, p, m) << "\n";
    }

    return 0;
}
