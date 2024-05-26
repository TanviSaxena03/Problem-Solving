#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int func(vector<int>& coins, int am, int res, vector<int>& dp){
        if(am==0) return 0;
        if(am<0) return INT_MAX;
        if(dp[am]!=-1) return dp[am];
        int mini=INT_MAX;
        for(int i=coins.size()-1;i>=0;i--){
            int ans=func(coins,am-coins[i],res,dp);
            if(ans!=INT_MAX) {
                mini=min(mini,1+ans);
            }
        }
        dp[am]=mini;
        return dp[am];
    }

    int coinChange(vector<int>& coins, int amount) {
        int res=INT_MAX;
        vector<int> dp(amount+1,-1);
        int ans=func(coins,amount,res,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};