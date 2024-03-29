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
    int find(TreeNode* root,int sum){
        if(root==NULL || sum<-19999999){
            return 0;
        }
        int res=0;
        if(root->val==sum){
           res++;
        }
        res+=find(root->left,sum-root->val);
        res+=find(root->right,sum-root->val);
        return res;
    }

    int pathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return 0;
        }
        return pathSum(root->left,sum)+find(root,sum)+pathSum(root->right,sum);
    }
};