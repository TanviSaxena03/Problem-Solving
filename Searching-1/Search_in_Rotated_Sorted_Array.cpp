#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int n=nums.size();
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int m=(s+e)/2;
        if (nums[m]==target)
            return m;
        else if (nums[m]>=nums[s])
        {
            if (target>=nums[s] && target<nums[m])
                e=m-1;
            else
                s=m+1;
        }
        else
        {
            if (target<=nums[e] && target>nums[m])
                s=m+1;
            else
                e=m-1;
        }
    }
    return -1;
}