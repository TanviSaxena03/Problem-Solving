#include<bits/stdc++.h>
#include<vector>
using namespace std;

class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n+1,-1);
    }

    int find(int x) {
        int root=x;
        while (parent[root]>=0) {
            root=parent[root];
        }
        while (parent[x]>=0) {
            int next=parent[x];
            parent[x]=root;
            x=next;
        }
        return root;
    }

    void unionz(int x,int y) {
        int r1=find(x);
        int r2=find(y);
        if (r1==r2)
            return;
        if (parent[r1]<parent[r2]) {
            parent[r1]+=parent[r2];
            parent[r2]=r1;
        } else {
            parent[r2]+=parent[r1];
            parent[r1]=r2;
        }
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        int m=requests.size();
        vector<bool> res(m,0);
        DSU uf(n);
        for(int i=0;i<m;i++) {
            DSU temp=uf;
            temp.unionz(requests[i][0],requests[i][1]);
            bool flag=true;
            for(vector<int>& v:restrictions) {
                if(temp.find(v[0])==temp.find(v[1])) {
                    flag=false;
                    break;
                }
            }
            if(flag) {
                res[i]=true;
                uf.unionz(requests[i][0],requests[i][1]);
            }
        }
        return res;
    }
};