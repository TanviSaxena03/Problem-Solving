#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int a,b,x=0,y=0,n=0;
        int res=0;
        for (auto i:fruits){
            if (i==b){
                y++;
                n++;
            }
            else if (i==a){
                int temp=a;
                a=b;
                b=temp;
                temp=x;
                x=y;
                y=temp+1;
                n=1;
            }
            else{
                a=b;
                b=i;
                x=n;
                y=1;
                n=1;
            }
            res=max(res,x+y);
        }
        return res;
    }
};