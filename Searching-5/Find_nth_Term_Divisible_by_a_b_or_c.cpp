#include <bits/stdc++.h>
using namespace std;
int hcf(int a,int b){
    if (b==0)
        return a;
    return hcf(b,a%b);
}

int lcm(int a,int b){
    return (a*b)/hcf(a,b);
}
 
int divCnt(int a,int b,int c,int num){
    return ((num/a)+(num/b)+(num/c)-(num/lcm(a,b))-(num/lcm(b,c))-(num/lcm(a,c))+(num/lcm(a,lcm(b,c))));
}
 
int findNth(int a,int b,int c,int n){
    int low=1,high=INT_MAX,mid;
    while (low<high) {
        mid=(low+high)/2;
        if (divCnt(a,b,c,mid)<n)
            low=mid+1;
        else
            high=mid;
    }
    return low;
}
 
int main(){
 
    cout<<findNth(2,3,5,10)<<endl<<findNth(3,5,7,10);
    return 0;
}