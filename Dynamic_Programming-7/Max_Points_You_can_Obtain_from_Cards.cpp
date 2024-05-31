#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int m=0;
        int n=cardPoints.size();
        vector<int> left(k+1);
        vector<int> right(k+1);
        left[0]=0;
        right[0]=0;
        for (int i=1;i<=k;i++){
            left[i]=left[i-1]+cardPoints[i-1];
            right[i]=right[i-1]+cardPoints[n-i];
        }
        for (int i=0;i<=k;i++){
            int s=left[i]+right[k-i];
            m=max(s,m);
        }
        return m;
    }
};