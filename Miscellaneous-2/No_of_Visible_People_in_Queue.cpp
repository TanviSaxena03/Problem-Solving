#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        vector<int> res(n);
        if(n==1) return res;
        for (int i=n-1;i>=0;i--){
            int cnt=1;
            while (!st.empty() && heights[i]>=st.top()){
                cnt++;
                st.pop();
            }
            if (st.empty()) cnt--;
            res[i]=cnt;
            st.push(heights[i]);
        }
        return res;
    }
};