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
    TreeNode* solve(vector<int>& nums, int l, int r) {
        if (l<=r) {
            int m=l+(r-l)/2;
            TreeNode* root=new TreeNode(nums[m]);
            root->left=solve(nums,l,m-1);
            root->right=solve(nums,m+1,r);
            return root;
        }
        return nullptr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);                
    }
};