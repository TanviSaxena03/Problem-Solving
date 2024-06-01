#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l=0;
        int r=0;
        int n=nums.size();
        map<int,int> mp;
        int res=0;
        while (r<n){
            mp[nums[r]]++;
            while((mp.rbegin()->first-mp.begin()->first)>limit){
                mp[nums[l]]--;
                if (mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};