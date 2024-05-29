#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(int row,int col,vector<vector<int>> &arr,vector<vector<int>> &dp)
    {
        int m=arr.size();
        int n=arr[0].size();
        if(row>=m || col>=n) return INT_MAX;
        if(row==m-1 && col==n-1){
            if(arr[row][col]>=0) return dp[row][col]=1;
            else return dp[row][col]=abs(arr[row][col])+1;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int a=solve(row,col+1,arr,dp);
        int b=solve(row+1,col,arr,dp);
        int health=min(a,b);
        int gain=arr[row][col];
        int needed=health-gain;
        if(needed>0) return dp[row][col]=needed;
        else return dp[row][col]=1;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,dungeon,dp);
    }
};