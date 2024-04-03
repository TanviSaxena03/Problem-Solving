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
    int s=0;
    void sumBST(TreeNode* root, int low, int high){
        if (root==NULL) return;
        if (root->val>=low && root->val<=high) s+=root->val;
        sumBST(root->left,low,high);
        sumBST(root->right,low,high);
        return;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        sumBST(root,low,high);
        return s;      
    }
};