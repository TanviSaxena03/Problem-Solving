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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int target,vector<int> temp){
        if(!root)
        return;
        target-=root->val;
        temp.push_back(root->val);
        if(target==0 && !root->left && !root->right)
        ans.push_back(temp);
        dfs(root->left,target,temp);
        dfs(root->right,target,temp);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root,target,{});
        return ans;
    }
};