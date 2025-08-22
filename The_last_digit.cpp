// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         long long a, b;
//         cin >> a >> b;

//         int lastDigit = a % 10;

//         // Precompute cycles for last digits
//         vector<vector<int>> cycles = {
//             {0},        // 0^n -> always 0
//             {1},        // 1^n -> always 1
//             {2, 4, 8, 6},
//             {3, 9, 7, 1},
//             {4, 6},
//             {5},        // always 5
//             {6},        // always 6
//             {7, 9, 3, 1},
//             {8, 4, 2, 6},
//             {9, 1}
//         };

//         vector<int> cycle = cycles[lastDigit];
//         int len = cycle.size();

//         // Find index in cycle
//         int pos = b % len;
//         if (pos == 0) pos = len;

//         cout << cycle[pos - 1] << "\n";
//     }
//     return 0;
// }

#include<iostream>
using namespace std;
int main(){
    int t,a;
    unsigned b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int c=a%10,r=1;
        if(c==0||c==1||c==5||c==6)r=c;
        else{
            int p[4];
            for(int i=0;i<4;i++)p[i]=i==0?c:(p[i-1]*c)%10;
            r=p[(b-1)%4];
        }
        cout<<r<<'\n';
    }
}
