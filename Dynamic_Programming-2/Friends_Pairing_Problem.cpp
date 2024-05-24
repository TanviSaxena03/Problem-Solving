#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countFriendsPairings(int n) { 
        int mod=1e9+7;
        if (n<=2)
            return n;
        long long a=1,b=2;
        for(int i=3;i<=n;i++){
            long long res=(b+((i-1)*a)%mod)%mod;
            a=b;
            b=res;
        }
        return b;
    }
};    