#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int countEl(vector<int>&v, int x){
    int low=0;
    int high=v.size()-1;
    int cnt=0;
    while(low<=high){
        int mid=(low+high)/2; 
        if(v[mid]<x){        
            cnt=(mid+1);
            low=mid+1;
        }   
        else
            high=mid-1;
    }
    return cnt;
}

int findMedian(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    int low=INT_MAX;
    int high=INT_MIN;
    for(int i=0;i<n;i++){
        low=min(low,A[i][0]);
        high=max(high,A[i][m-1]);
    }
    int ans;
    while(low<=high){
        int mid=(low+high)/2;
        int c=0;
        for(int i=0;i<n;i++)
            c+=countEl(A[i],mid);
        if(c<=(n*m/2)){
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    return ans;            
}
