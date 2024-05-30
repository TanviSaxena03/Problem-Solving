#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public: 
    int topDown(string& word1,string& word2,int i,int j,vector<vector<int>>& dp){
        if(i>=word1.length())
            return word2.length()-j;
        if(j>=word2.length())
            return word1.length()-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int res=INT_MAX;
        if(word1[i]==word2[j])
            res=topDown(word1,word2,i+1,j+1,dp);
        else{
            int rep=topDown(word1,word2,i+1,j+1,dp);
            int del=topDown(word1,word2,i+1,j,dp);
            int ins=topDown(word1,word2,i,j+1,dp);
            res=min(rep,min(del,ins))+1;
        }
        dp[i][j]=res;
        return dp[i][j];
    }      
    int minDistance(string word1, string word2) {
        int i=0,j=0;
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        return topDown(word1,word2,i,j,dp);
    }
};