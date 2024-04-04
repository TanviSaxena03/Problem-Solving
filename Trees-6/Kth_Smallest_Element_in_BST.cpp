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
    vector<int> v;
    void inord(TreeNode* root){
        if(root!=NULL){
            inord(root->left);
            v.push_back(root->val);
            inord(root->right);
        }
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        inord(root);
        return v[k-1];
    }
};