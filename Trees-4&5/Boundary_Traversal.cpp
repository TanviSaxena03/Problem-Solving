#include<bits/stdc++.h>
#include<vector>
using namespace std;

template <typename T>
class TreeNode{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~TreeNode(){
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

bool isleaf(TreeNode<int> *root) { 
    return (!root->left && !root->right); 
    }

void leftb(TreeNode<int>*root,vector<int>&result){
    TreeNode<int>*curr=root->left;
    while(curr){
      if (!isleaf(curr)) {
        result.push_back(curr->data);
      }
      if (curr->left) curr=curr->left;
      else curr=curr->right;
    }
}
 
void rightb(TreeNode<int>*root,vector<int>&result){
    TreeNode<int>*curr=root->right;
    vector<int>temp;
    while(curr){
        if(!isleaf(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;--i){
        result.push_back(temp[i]);
    }
}

void leafn(TreeNode<int>*root,vector<int>&result){
    if(isleaf(root)){
        result.push_back(root->data);
        return;
    }
    if(root->left) leafn(root->left, result);
    if(root->right) leafn(root->right, result);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{  
    vector<int>res;
    if(root==NULL){
        return res;
    }
    if(!isleaf(root)){
        res.push_back(root->data);
    }
    leftb(root,res);
    leafn(root,res);
    rightb(root,res);
    return res;
}