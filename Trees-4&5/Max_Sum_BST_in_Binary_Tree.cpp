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

class branch{
public:
   int ma; 
   int mi;
   bool isBst;
   int sum;
};

branch solve(TreeNode*root,int &ans){
    if(!root) return {INT_MIN,INT_MAX,true,0};
    branch left=solve(root->left,ans);
    branch right=solve(root->right,ans);
    branch curr;
    curr.sum=left.sum+right.sum+root->val;
    curr.ma=max(root->val,right.ma);
    curr.mi=min(root->val,left.mi);
    if(left.isBst&&right.isBst&&(root->val>left.ma&&root->val<right.mi)){
        curr.isBst=true;
    }
    else curr.isBst=false;
    if(curr.isBst){
        ans=max(ans,curr.sum);
    }
    return curr;
}

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxs=0;
        branch a=solve(root,maxs);
        return maxs;        
    }
};