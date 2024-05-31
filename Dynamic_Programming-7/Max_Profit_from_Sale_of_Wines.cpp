#include<bits/stdc++.h>
#include<vector>
using namespace std;
 
int solve(vector<int> &pr, int st, int end, int n,vector<vector<int>> &s, vector<vector<int>> &dp) {
    if (dp[st][end]!=-1) return dp[st][end];
    int y=n-(end-st); 
    if (st==end) return pr[st]*y;    
    int a=y*pr[st]+solve(pr,st+1,end,n,s,dp);
    int b=y*pr[end]+solve(pr,st,end-1,n,s,dp);
    dp[st][end]=max(a,b);
    if (a>=b) s[st][end]=0;
    return dp[st][end];
}

int maxProfit(vector<int> price, int n) {
    vector<vector<int>> dp(n,vector<int>(n,-1));
    vector<vector<int>> s(n,vector<int>(n,1));
    int res=solve(price,0,n-1,n,s,dp);
    int i=0;
    int j=n-1;
    while (i<=j) {
        if (s[i][j]==0) {
            cout<<"beg"<<endl;
            i++;
        }  
        else {
            cout<<"end"<<endl;
            j--;
        }
    }
    return res;
}
 
int main() {
    int n;
    cin>>n;
    vector<int> price(n);
    for (int i=0;i<n;i++){
        cin>>price[i];
    }
    cout<<maxProfit(price,n)<<endl;
    return 0;
}
