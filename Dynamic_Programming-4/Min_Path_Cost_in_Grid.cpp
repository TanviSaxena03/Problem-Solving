#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &cost, vector<vector<int>> &dp) {
        if (i==n-1) return grid[i][j];
        if (dp[i][j]!=-1) return dp[i][j];
        int res=INT_MAX;
        for (int k=0;k<m;k++) {
            res=min(res,grid[i][j]+cost[grid[i][j]][k]+dfs(i+1,k,n,m,grid,cost,dp));
        }
        return dp[i][j]=res;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size();
        int m=grid[0].size();
        int res=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for (int r=0;r<m;r++) {
            for (int c=0;c<m;c++) {
                res=min(res,grid[0][r]+moveCost[grid[0][r]][c]+dfs(1,c,n,m,grid,moveCost,dp));
            }  
        }
        return res;
    }
};