#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int NthRoot(int n, int m){
        long low=1;
        long high=m;
        while(low<=high){
            long mid=(low+high)/2;
            long ans=1;
            long temp=n;
            while(temp--){
                ans*=mid;
                if(ans>m) break;
            }
            if(ans==m){
                return mid;
            }else if(ans>m){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;
    }
};