#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int countstudent(vector<int>& arr,int pages){
    int st=1;
    long long pagest=0;
    for (int i=0;i<arr.size();i++){
        if (pagest+arr[i]<=pages){
            pagest+=arr[i];
        }
        else {
            st++;
            pagest=arr[i];
        }
    }
    return st;
}

int findLargestMinDistance(vector<int> &arr, int k)
{
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while (low<=high){
        int mid=(low+high)/2;
        int st=countstudent(arr, mid);
        if(st>k)
            low=mid+1;
        else 
            high=mid-1;
    }
    return low;
}