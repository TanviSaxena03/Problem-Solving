#include<bits/stdc++.h>
#include<vector>
using namespace std;

int diceCombi(int n){
    vector<int> dp(n+1);
    int mod=1e9+7;
    dp[0]=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=6;j++){
            if (j<=i){
                dp[i]=(dp[i]+dp[i-j])%mod;
            }
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<diceCombi(n);
    return 0;
}