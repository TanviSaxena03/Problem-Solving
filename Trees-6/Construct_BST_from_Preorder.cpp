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
int i=0;
    TreeNode* createBST(vector<int>& preorder,int st,int end){
        if(st>end) return NULL;
        int curr=preorder[i];
        TreeNode* root=new TreeNode(preorder[i++]);
        int j;
        for(j=i;j<preorder.size();j++){
            if(preorder[j]>curr) break;
        }
        root->left=createBST(preorder,i,j-1);
        root->right=createBST(preorder,j,end);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return createBST(preorder,0,preorder.size()-1);   
    }
};