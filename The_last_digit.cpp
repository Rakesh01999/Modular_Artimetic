#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;cin>>t;
    while(t--){
        long long a,b;cin>>a>>b;
        if(b==0){cout<<1<<"\n";continue;}
        int cycle[4],len=0,last=a%10;
        cycle[len++]=last;
        for(int i=1;i<4;i++){
            int d=(cycle[i-1]*last)%10;
            if(d==cycle[0]) break;
            cycle[len++]=d;
        }
        cout<<cycle[(b-1)%len]<<"\n";
    }
}
