#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int i=0;
        int j=0;
        int res=0;
        int ho=houses.size();
        int he=heaters.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        vector<int> v(ho,INT_MAX);
        for (int i=0;i<ho;i++){
            while (j+1<he && houses[i]>=heaters[j+1] && houses[i]>=heaters[j]){
               j++;
           }
           int a=abs(houses[i]-heaters[j]);
           int b=INT_MAX;
           if(j+1<he){
           b=abs(houses[i]-heaters[j+1]);
           }
           v[i]=min(a,b);
        }
        for(int i=0;i<ho;i++){
            res=max(res,v[i]);
        }
        return res;
    }
};