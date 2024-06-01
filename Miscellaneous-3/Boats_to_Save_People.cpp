#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0;
        int res=0;
        int n=people.size();
        int j=n-1;
        while (i<=j){
            if (people[i]+people[j]<=limit){
                i++;
                j--;
                res++;
            }
            else {
                res++;
                j--;
            }
        }
        return res;
    }
};