#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int possibleBouquets(vector<int> &bloomDay, int n, int k, long long mid) {
        int b=0, c=0;
        for(int i=0;i<n;i++) {
            if (bloomDay[i]<=mid) {
                c++;
            }
            else {
                b+=(c/k);
                c=0;
            }
        } 
        b+=(c/k);
        return b;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {      
        int n=bloomDay.size();
        if(n<(long long)m*k)
            return -1;
        long long low=1, high=*max_element(bloomDay.begin(), bloomDay.end());
        long long ans=high;
        while(low<=high) {
            long long mid=(low+high)>>1;
            int b=possibleBouquets(bloomDay,n,k,mid);
            if(b>=m) {
                ans=min(ans,mid);
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }    
};