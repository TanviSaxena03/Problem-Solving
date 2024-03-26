#include<bits/stdc++.h>
#define MAX 1000
using namespace std;


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int low=mat[0][0];
    int high=mat[n-1][n-1];
    while(low<high){
        int c=0;
        int mid=(low+high)/2;
        for(int i=0;i<n;i++){
            c+=upper_bound(mat[i],mat[i]+n,mid)-mat[i];
        }
        if(c<k){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return low;
}