#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(int n, int pre, vector<int> &nums, vector<vector<int>> &dp){
        if (n==nums.size()) return 0;
        if (dp[n][pre+1]!=-1) return dp[n][pre+1];
        int a=solve(n+1,pre,nums,dp);
        int b=0;
        if (pre==-1 || nums[n]>nums[pre]){
            b=1+solve(n+1,n,nums,dp);
        }
        return dp[n][pre+1]=max(a,b);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};