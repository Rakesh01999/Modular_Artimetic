#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast exponentiation (a^b mod m)
ll mod_pow(ll base, ll exp, ll mod)
{
    ll result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main()
{
    ll a, b, n;
    cin >> a >> b >> n;

    // Compute modular inverse of b
    ll b_inv = mod_pow(b, n - 2, n);

    // Compute (a * b^-1) % n
    ll ans = (a * b_inv) % n;
    cout << ans << "\n";
    return 0;
}
