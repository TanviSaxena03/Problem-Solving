#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    map<int,vector<pair<int,int>>> mp;
    void solve(TreeNode* root,int lvl,int hlvl){
        if(root==NULL){
            return;
        }
        mp[lvl].push_back({hlvl,root->val});
        solve(root->right,lvl+1,hlvl+1);
        solve(root->left,lvl-1,hlvl+1);        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root,0,0);
        for(auto it:mp){
            vector<int> temp;
            vector<pair<int,int>> v2 = it.second;
            map<int,vector<int>> mp2;
            for(auto it2: v2){
                mp2[it2.first].push_back(it2.second);
            }
            for(auto x: mp2){
                vector<int> v3 = x.second;
                sort(v3.begin(),v3.end());
                temp.insert(temp.end(),v3.begin(),v3.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};