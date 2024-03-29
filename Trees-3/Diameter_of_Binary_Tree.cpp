#include<bits/stdc++.h>
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        getDiameter(root,ans);
        return ans-1;
    }
    
    int getDiameter(TreeNode* root, int& ans){
        if(root==NULL) return 0;
        int l=getDiameter(root->left,ans);
        int r=getDiameter(root->right,ans);
        ans=max(ans,l+r+1);
        return max(l,r)+1;      
    }
};