#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int high=*max_element(nums.begin(),nums.end());
        int low=1;
        int res=high;
        while (low<high){
            int p=(low+high)/2;
            int ops=0;
            for (int i=0;i<nums.size();i++){
                if (nums[i]>p){
                    if (nums[i]%p==0){
                        ops+=nums[i]/p-1;
                    }
                    else{
                    ops+=nums[i]/p;
                    }
                }
            }
            if (ops<=maxOperations){
                res=p;
                high=p;
            } else{
                low=p+1;
            }
        }
        return res;
    }
};