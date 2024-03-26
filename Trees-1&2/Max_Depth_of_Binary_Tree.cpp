#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxl,maxr;
        if (root==NULL)
        {
            return 0;
        }
        maxl=maxDepth(root->left);
        maxr=maxDepth(root->right);
        return max(maxl,maxr)+1;
    }
};