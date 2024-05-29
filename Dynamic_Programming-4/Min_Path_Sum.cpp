#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int paths(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if (m==0 && n==0) return dp[0][0];
        if (dp[m][n]!=-1) return dp[m][n];
        int a=paths(m-1,n,grid,dp);
        int b=paths(m,n-1,grid,dp);
        return dp[m][n]=min(a,b)+grid[m][n];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
        for(int j=1;j<m;j++){
            dp[j][0]=grid[j][0]+dp[j-1][0];
        }
        return paths(m-1,n-1,grid,dp);
    }
};