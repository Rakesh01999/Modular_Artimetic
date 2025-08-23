#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
#define ll long long

ll mod_pow(ll base, ll exp, ll mod)
{
    ll result = 1;
    while (exp)
    {
        if (exp %2 != 0)
        {
            result = (result * base ) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h;
    cin >> w >> h;

    cout << mod_pow(2, w + h, MOD) << '\n';
    return 0;
}
