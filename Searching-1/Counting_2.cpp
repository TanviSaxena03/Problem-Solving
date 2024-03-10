#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n,q,i;
  cin>>n;
  cin>>q;
  vector<int> a(n);
  vector<int> x(q);
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  for(i=0;i<q;i++){
    cin>>x[i];
  }
  sort(a.begin(),a.end());
  int c=-1;
  for(i=0;i<q;i++){
    int low=0;
    int high=a.size()-1;
    c=-1;
    while(low<=high){
      int m=(low+high)/2;
      if (a[m]>=x[i]){
        c=m;
        high=m-1;
      }
      else if(a[m]<x[i])
        low=m+1;
    }
    if(c==-1)
      cout<<0<<endl;
    else
      cout<<a.size()-c<<endl;
  }
  return 0;
}
