#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findParent(int node,vector<int> &par){
        if (node==par[node]) return node;
        return par[node]=findParent(par[node],par);
    }

    void Union(int x,int y,vector<int> &par,vector<int> &rank){
        x=findParent(x,par);
        y=findParent(y,par);   
        if (x==y) return;
        if (rank[x]<rank[y]) par[x]=y;
        else if (rank[y]<rank[x]) par[y]=x;
        else {
            par[x]=y;
            rank[y]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        vector<int> par(n);
        vector<int> rank(n,0);
        for (int i=0;i<n;i++){
            par[i]=i;
        }
        for (int i=0;i<allowedSwaps.size();i++){
            int x=allowedSwaps[i][0];
            int y=allowedSwaps[i][1];
            Union(x,y,par,rank);
        }
        map<int,map<int,int>> mp;
        for (int i=0;i<n;i++){
            int x=findParent(i,par);
            mp[x][source[i]]++;
        }
        int res=0;
        for (int i=0;i<n;i++){
            int x=findParent(i,par);
            if (target[i]==source[i]){
                if (mp[x][target[i]]>0) mp[x][target[i]]--;
                else res++;
            }
            else {
                if (mp[x].find (target[i])!=mp[x].end() && mp[x][target[i]]>0)
                    mp[x][target[i]]--;
                else res++;
            }
        }
        return res;
    }
};