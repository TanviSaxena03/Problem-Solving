#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int heightOfBinaryTree(TreeNode<int> *root){
    int maxl,maxr;
        if (root==NULL){
            return 0;
        }
        maxl=heightOfBinaryTree(root->left);
        maxr=heightOfBinaryTree(root->right);
        return max(maxl,maxr)+1;
}