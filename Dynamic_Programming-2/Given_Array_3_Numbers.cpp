#include<bits/stdc++.h> 
#include<vector>
using namespace std; 
  
int maxi(int a[],int n,int x,int y,int z) {   
    vector<int> left(n); 
    left[0]=a[0]*x; 
    for (int i=1;i<n;i++)  
        left[i]=max(left[i-1],x*a[i]);   
    vector<int> right(n); 
    right[n-1]=a[n-1]*z; 
    for (int i=n-2;i>=0;i--) 
        right[i]=max(right[i+1],z*a[i]); 
    int res=INT_MIN;  
    for (int i=0;i<n;i++)  
          res=max(res,left[i]+y*a[i]+right[i]);  
    return res; 
}

int main(){
    int n,x,y,z; 
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>x>>y>>z;
    cout<<maxi(a,n,x,y,z)<<endl; 
    return 0; 
} 