#include<bits/stdc++.h>
#include<vector>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int ma=0;
        int currma=0;
        int j=0;
        for(int i=0;i<nums.size()-1;i++){
            ma=max(ma,i+nums[i]);
            if(i==currma){
                j++;
                currma=ma;
            }
        }
        return j;
    }
};