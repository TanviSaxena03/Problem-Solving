#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& coins, int n, int t, vector<vector<int>>& dp, int ind) {
        if (t==0) return 1;
        if (ind>=n) return 0;
        if (t<0) return 0;
        if (dp[ind][t]!=-1) return dp[ind][t];
        int take=solve(coins,n,t-coins[ind],dp,ind);
        int nottake=solve(coins,n,t,dp,ind+1);
        return dp[ind][t]=take+nottake;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return solve(coins,n,amount,dp,0);
    }
};