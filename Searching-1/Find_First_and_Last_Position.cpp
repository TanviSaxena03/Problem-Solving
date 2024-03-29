#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int firstOccur(vector<int>&a, int t){
        int low=0;
        int high=a.size()-1;
        int res=-1;
        int m=(low+high)/2;
        while(low<=high){
            if(a[m]==t){
                res=m;
                high=m-1;
            }
            else if(t<a[m])
                high=m-1;
            else
                low=m+1;
            m=(low+high)/2;
        }
        return res;
    }
    int lastOccur(vector<int>&a, int t){
        int low=0;
        int high=a.size()-1;
        int res=-1;
        int m=(low+high)/2;
        while(low<=high){
            if(a[m]==t){
                res=m;
                low=m+1;
            }
            else if(t<a[m])
                high=m-1;
            else
                low=m+1;
            m=(low+high)/2;
        }
        return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return{firstOccur(nums,target),lastOccur(nums,target)};
    }
};