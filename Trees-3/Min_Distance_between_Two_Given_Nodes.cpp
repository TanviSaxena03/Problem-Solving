#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution{
    public:
    Node*ancestor(Node*root,int a,int b){
        if(!root)
            return root;
        if(root->data==a || root->data==b)
            return root;
        Node*left=ancestor(root->left,a,b);
        Node*right=ancestor(root->right,a,b);
        if(left && right)
            return root;
        else if(left)
            return left;
        else if(right)
            return right;
        return NULL;
    }
    
    int height(Node*root,int x ,int dis){
        if(!root)
            return -1;
        if(root->data==x)
            return dis;
        int left=height(root->left,x,dis+1);
        if(left!=-1)
            return left;
        return height(root->right,x,dis+1);
    }
    
    int findDist(Node* root, int a, int b) {
        Node* temp=ancestor(root,a,b);
        int h1=height(temp,a,0);
        int h2=height(temp,b,0);
        return h1+h2;
    }
};