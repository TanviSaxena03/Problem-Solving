#include<bits/stdc++.h>
#include<vector>
using namespace std;

class DSU {
private:
	vector<int> parent, rank;

public:
	DSU(int size) {
		parent=vector<int>(size);
		iota(begin(parent),end(parent),0);
		rank=vector<int>(size,0);
	}

	int find(int i) {
		if (parent[i]!=i) {
			parent[i]=find(parent[i]);
		}
		return parent[i];
	}

	bool unionn(int x,int y) {
		int xroot=find(x);
		int yroot=find(y);
		if (xroot==yroot) {
			return true;
		}
		else {
			if (rank[xroot]<rank[yroot]) {
				parent[xroot]=yroot;
			}
			else if (rank[xroot]>rank[yroot]) {
				parent[yroot]=xroot;
			}
			else {
				parent[yroot]=xroot;
				rank[xroot]++;
			}
			return false;
		}
	}
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<bool> indeg(edges.size()+1,false); 
		vector<int> rem={ }; 
		for (int i=0;i<edges.size();i++) {
			if (indeg[edges[i][1]]==0) { 
				indeg[edges[i][1]]=1;
			}
			else { 
				rem=edges[i];
				edges.erase(edges.begin()+i);
				i--;
			}
		}
		vector<int> loope={ }; 
		DSU uf(edges.size()+2); 
		for (vector<int> e:edges) {
			if (uf.unionn(e[0],e[1])) {
				loope=e;
				break;
			}
		}
		if (not rem.empty() && loope.empty()) {
			return rem;
		}
		else if (not rem.empty()) {
			for (int i=0;i<edges.size();i++) {
				if (edges[i][1]==rem[1]) return edges[i];
			}
		}
		else {
			return loope;
		}
		return {};  
    }
};