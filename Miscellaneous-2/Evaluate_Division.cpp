#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double dfs(string s, string d, unordered_map<string,vector<pair<string,double>>> &adj, set<string> &vis){
        if (vis.find(s)!=vis.end()) return -1.0;
        if (s==d) return 1.0;
        vis.insert(s);
        for (auto ne:adj[s]){
            double temp=dfs(ne.first,d,adj,vis);
            if (temp!=-1.0) return temp*ne.second;
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        set<string> nodes;
        for (int i=0;i<equations.size();i++){
            auto eq=equations[i];
            adj[eq[0]].push_back({eq[1],values[i]});
            adj[eq[1]].push_back({eq[0],(double)(1/values[i])});
            nodes.insert(eq[0]);
            nodes.insert(eq[1]);
        }
        vector<double> res;
        for (auto q:queries){
            set<string> vis;
            if ((nodes.find(q[0])==nodes.end()) || (nodes.find(q[1])==nodes.end())){
                res.push_back(-1);
            }
            else{
                res.push_back(dfs(q[0],q[1],adj,vis));
            }
        }
        return res;
    }
};