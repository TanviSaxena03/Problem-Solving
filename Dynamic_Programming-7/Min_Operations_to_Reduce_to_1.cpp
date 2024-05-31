#include<bits/stdc++.h>
#include<vector>
using namespace std;

int ops(int x){
    if (x<=1) return 0;
    vector<int> dp(x+1);
    dp[2]=1;
    dp[3]=1;
    for (int i=4;i<=x;i++){
        int a=(i%2==0)?dp[i/2]:INT_MAX;
        int b=(i%3==0)?dp[i/3]:INT_MAX;
        int c=dp[i-1];
        dp[i]=1+min(min(a,b),c);
    }
    return dp[x];
}

int main(){
    int n;
    cin>>n;
    cout<<ops(n)<<endl;
}