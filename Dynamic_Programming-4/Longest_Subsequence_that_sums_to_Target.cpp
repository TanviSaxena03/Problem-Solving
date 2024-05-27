#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(int i, int t, vector<int>& nums, vector<vector<int>>& dp){
        if (t==0) return 1;
        if (i<0) return -1e9;
        if (dp[i][t]!=-1) return dp[i][t];
        int take=-1e9;
        if (nums[i]<=t){
            take=1+solve(i-1,t-nums[i],nums,dp);
        }
        int nottake=solve(i-1,t,nums,dp);
        return dp[i][t]=max(take,nottake);
    } 

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int ans=solve(n-1,target,nums,dp)-1;
        return max(ans,-1);
    }
};