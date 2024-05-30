#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(i>=0 && j<0){
            for(int a=0;a<=i;a++){
                if(s[a]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j] || s[i]=='?'){
            return dp[i][j]=solve(i-1,j-1,s,p,dp);
        }
        if(s[i]=='*'){
            return dp[i][j]=solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp);
        }
        return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        int m=p.size();
        int n=s.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,p,s,dp);
    }
};