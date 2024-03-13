#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        if(nums[low]==target || nums[high]==target)
            return true;
        else if(nums[low]<target)
            low++;
        else if(nums[high]>target)
            high--;
        else
            return false;
    }
    return false;    
}