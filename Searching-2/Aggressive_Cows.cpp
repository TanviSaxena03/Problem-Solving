#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

bool func(vector<int>s, int n, int k, int m){
        int e=s[0];
        int i,c=1;
        for(i=1;i<n;i++){
            if(s[i]-e>=m){
                e=s[i];
                c++;
            }
        }
        if(k<=c)
            return true;
        else
            return false;
    }

int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());
        int res=-1;
        int low=0;
        int high=stalls[n-1]-stalls[0];
        while(low<=high){
            int m=(low+high)/2;
            if(func(stalls,n,k,m)==true){
                low=m+1;
                res=m;
            }
            else
                high=m-1;
        }
        return res;
    }