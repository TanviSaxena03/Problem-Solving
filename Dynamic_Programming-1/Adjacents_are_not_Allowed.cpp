#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution{
public:
    int maxSum(int N, vector<vector<int>> mat)
    {
        vector<int> dp(N);
        for (int i=0;i<N;i++){
            dp[i]=max(mat[0][i],mat[1][i]);
        }
        vector<int> res(N);
        res[0]=dp[0];
        res[1]=dp[1];
        res[2]=dp[0]+dp[2];
        for (int i=3;i<N;i++){
            res[i]=max(res[i-2],res[i-3])+dp[i];
            res[i]=max(res[i-1],res[i]);
        }
        return res[N-1];
    }
};