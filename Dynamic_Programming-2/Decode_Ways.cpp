#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int func(string& s, vector<int>& dp, int i){
        if(i==s.size()) 
            return 1;       
        if(s[i]=='0') 
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int notpick=func(s,dp,i+1);
        int pick=0;
        if (i<s.size()-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))) {
            pick=func(s,dp,i+2);
        }
        return dp[i]=pick+notpick;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        if(s.empty() || s[0]=='0')
            return 0;
        return func(s,dp,0);    
    }
};