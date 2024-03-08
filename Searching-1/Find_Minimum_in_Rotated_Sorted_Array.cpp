#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        if(nums.size()==1)
            return nums[0];
        while(s<=e)
        {
            int m=(s+e)/2;
            if (nums[m]>nums[m+1])
                return nums[m+1];
            else if ((m==0) && (nums[m]<nums[m+1]))
                return nums[m];
            else if ((nums[m]>nums[e]) && (nums[m]>nums[s]))
                s=m+1;
            else
                e=m;           
        }
        return -1;       
    }

    int main(){
        vector<int> a ={5,6,7,8,0,1,2,3};
        int res=findMin(a);
        cout<<res;
        return 0;
    }

    