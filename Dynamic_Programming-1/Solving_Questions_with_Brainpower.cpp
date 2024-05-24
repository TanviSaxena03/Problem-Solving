#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,0);
        reverse(questions.begin(),questions.end());
        for(int i=0;i<n;i++){
            if(i) 
                dp[i]=max(dp[i],dp[i-1]);
            if(i-questions[i][1]-1<0)
                dp[i]=max(dp[i],(long long)questions[i][0]);
            else
                dp[i]=max(dp[i],dp[i-questions[i][1]-1]+(long long)questions[i][0]);
        }
        return dp[n-1];
    }
};