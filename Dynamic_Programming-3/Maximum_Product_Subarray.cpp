#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int s=1,e=1,i=0,j=n-1;
        int ma=nums[0];
        while(i<n){
            s=s*nums[i];
            e=e*nums[j];
            ma=max(ma,max(s,e));
            if (s==0) s=1;
            if (e==0) e=1;
            i++;
            j--;
        }
        return ma;
    }
};