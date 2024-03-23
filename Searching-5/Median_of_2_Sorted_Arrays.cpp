#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if (m>n)
            return findMedianSortedArrays(nums2,nums1);       
        int low=0, high=m;
        while(low<=high){
            int Px=low+(high-low)/2;
            int Py=((m+n+1)/2)-Px;
            int a=(Px==0)?INT_MIN:nums1[Px-1];
            int b=(Py==0)?INT_MIN:nums2[Py-1];
            int c=(Px==m)?INT_MAX:nums1[Px];
            int d=(Py==n)?INT_MAX:nums2[Py];
            if (a<=d && b<c){
                if ((m+n)%2==1){
                    return max(a,b);
                }
                return (max(a,b)+min(c,d))/2.0;
            }
            if(a>d){
                high=Px-1;
            }
            else{
                low=Px+1;
            }
        }
        return -1;
    }
};