#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int mini=INT_MAX;
        long long s=0;
        deque<pair<long long,int>> dq;
        for (int i=0;i<n;i++){
            s+=nums[i];
            if (s>=k)
                mini=min(mini,i+1);
            while (dq.size() && dq.front().first<=s-k){
                mini=min(mini,i-dq.front().second);
                dq.pop_front();
            }
            while (dq.size() && dq.back().first>=s)
                dq.pop_back();
            dq.push_back({s,i});
        }
        if (mini!=INT_MAX) return mini;
        return -1;
    }
};