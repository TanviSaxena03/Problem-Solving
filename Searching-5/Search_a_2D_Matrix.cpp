#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size()-1;
        int low=0;
        int high=matrix[0].size()-1;
        int ind=-1;
        while(low<=row){
            int mid=(low+row)/2;
            if(matrix[mid][0]<=target&&matrix[mid][high]>=target){
                ind=mid;
                break;
            }
            else if(matrix[mid][0]<target){
                low=mid+1;
            }
            else{
                row=mid-1;
            }           
        }
        if(ind==-1){
            return false;
        }      
        low=0;      
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[ind][mid]==target){
                return true;
            }
            else if(matrix[ind][mid]<target){         
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;        
    }
};