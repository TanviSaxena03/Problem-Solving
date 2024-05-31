#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int> &nums, vector<int> &mul,int i,int start, vector<vector<int>> &dp){
        if(i==mul.size()) return 0;
        if(dp[start][i]!=INT_MIN) return dp[start][i];
        int left=solve(nums,mul,i+1,start+1,dp)+nums[start]*mul[i];
        int right=solve(nums,mul,i+1,start,dp)+nums[nums.size()-1-(i-start)]*mul[i];
        return dp[start][i]=max(left,right);
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m=multipliers.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,INT_MIN));
        return solve(nums,multipliers,0,0,dp);
    }
};