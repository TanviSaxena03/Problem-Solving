#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cumsum=0;
        int m=INT_MIN;
        int i=0;
        while(i<nums.size()){
            cumsum=cumsum+nums[i];
            if (m<cumsum) m=cumsum;
            if (cumsum<0) cumsum=0;
            i++;
        }
        return m;
    }
};