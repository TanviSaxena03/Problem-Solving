#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    pair<int,int> solve(vector<int> &nums,int curr,int prev,vector<vector<pair<int,int>> >&dp) {
        if (curr==nums.size()) 
            return make_pair(0,1);
        if (dp[curr][prev+1].first!=-1) return dp[curr][prev+1];
        int len=0,cnt=0;
        if (prev==-1 || nums[prev]<nums[curr]){
            pair<int,int> incl=solve(nums,curr+1,curr,dp);
            int incLen=1+incl.first;
            len=incLen;
            cnt=incl.second;
        }
        pair<int,int> excl=solve(nums,curr+1,prev,dp);
        if (excl.first>len){
            len=excl.first;
            cnt=excl.second;
        } 
        else if (excl.first==len){
            cnt+=excl.second;
        }
        dp[curr][prev+1]=make_pair(len,cnt);
        return dp[curr][prev+1];
    }

    int findNumberOfLIS(vector<int>& nums) {
        int curr=0,prev=-1;
        vector<vector<pair<int,int>>> dp(nums.size(),vector<pair<int,int>>(nums.size()+1,make_pair(-1,-1)));
        pair<int,int> res=solve(nums,curr,prev,dp);
        return res.second;
    }
};