#include<bits/stdc++.h>
#include<vector>
using namespace std;

class DSU{
public:
    vector<int> size,parent;
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findpar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findpar(parent[node]);
    }  

    void unions(int u,int v){
        int upu=findpar(u);
        int upv=findpar(v);
        if(upu==upv) return;  
        if(size[upu]<size[upv]){
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else{
            parent[upv]=upu;
            size[upu]+=size[upv];
        }  
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();  
        DSU ds(n);
        vector<int> ans;
        pair<int,int> p;
        for(auto it:edges){
            if (ds.findpar(it[0])!=ds.findpar(it[1])) {
                ds.unions(it[0],it[1]);
            }
            else if (ds.findpar(it[0])==ds.findpar(it[1])) {
                p={it[0],it[1]};  
            }
        }
        ans.push_back(p.first); 
        ans.push_back(p.second);
        return ans;    
    }
};