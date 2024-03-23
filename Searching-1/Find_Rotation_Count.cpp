#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int low=0;
	    int high=n-1;
	    while(low<=high){
	        int m=(low+high)/2;
	        int next=(m+1)%n;
	        int prev=(m+n-1)%n;
	        if (arr[low]<=arr[high])
	            return low;
	        if (arr[m]<=arr[next] && arr[m]<=arr[prev])
	            return m;
	        if (arr[low]<=arr[m])
	            low=m+1;
	        else if (arr[m]<=arr[high])
	            high=m-1;
	    }
	    return -1;
	}

};