#include<bits/stdc++.h>
#include<vector>
using namespace std;

class DSU {
public: 
    vector<int> parent,size; 
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for (int i=0;i<=n;i++) {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findPar(int node) {
        if (node==parent[node])
            return node;
        return parent[node]=findPar(parent[node]);
    }

    void unions(int u, int v) {
        int ulpu=findPar(u);
        int ulpv=findPar(v);
        if (ulpu==ulpv) return;
        if (size[ulpu]<size[ulpv]) {
            parent[ulpu]=ulpv;
            size[ulpv]+=size[ulpu];
        }
        else {
            parent[ulpv]=ulpu;
            size[ulpu]+=size[ulpv];
        }
    }
}; 

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int cnt=0;
        int n=row.size();
        DSU ds(n);
        for (int i=0;i<n;i+=2) {
            ds.unions(i,i+1);
        } 
        for (int i=0;i<n;i+=2) {
            int left=ds.findPar(row[i]);
            int right=ds.findPar(row[i+1]);
            if(left!=right){
                ds.unions(left,right);
                cnt++;
            }
        }
        return cnt;
    }
};