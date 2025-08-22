#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 109546051211

int main(){
    ll n;cin>>n;
    vector<ll> v(n);
    if (n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    
    ll fact = 1, ans = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact = (fact * i) % mod;
        ans= (ans * fact) % mod;
    }
    cout<< ans  <<endl;
    return 0;
}