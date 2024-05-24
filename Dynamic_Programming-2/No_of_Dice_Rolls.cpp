#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int func(int n, int k, int target,vector<vector<int>>& dp){
        int mod=1e9+7;
        if (n==0 && target==0) 
            return 1;
        if (n<=0 || target<=0) 
            return 0;
        if (dp[n][target]!=-1) 
            return dp[n][target];
        int res=0;
        for (int i=1;i<=k;i++){
            res=(res+func(n-1,k,target-i,dp))%mod;
        }
        return dp[n][target]=res;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return func(n,k,target,dp);
    }
};