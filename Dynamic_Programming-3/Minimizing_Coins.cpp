#include<bits/stdc++.h>
#include<vector>
using namespace std;

int solve(int n,int am, vector<int> &coins){
    vector<int> dp(am+1,1e9);
    dp[0]=0;
    for (int i=1;i<=am;i++){
        for (int j=0;j<n;j++){
            if (coins[j]<=i){
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    if (dp[am]==1e9) return -1;
    return dp[am];
}

int main(){
    int n,am;
    cin>>n>>am;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<solve(n,am,coins);
    return 0;
}