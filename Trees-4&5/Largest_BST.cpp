#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data=val;
        left=right=NULL;
    }
};

class Solution{
    public:
    int maxv;
    int minv;
    bool isBST;
    int s;
    
    Solution solve(Node* root, int& maxans){
        if(root==NULL)
            return{INT_MIN,INT_MAX,true,0};
        Solution l=solve(root->left,maxans);
        Solution r=solve(root->right,maxans);
        Solution curr;
        curr.maxv=max(root->data,r.maxv);
        curr.minv=min(root->data,l.minv);
        curr.s=l.s+r.s+1;
        if(l.isBST && r.isBST && (root->data<r.minv && root->data>l.maxv)) 
            curr.isBST=true;
        else 
            curr.isBST=false;
        if(curr.isBST)
            maxans=max(maxans,curr.s);
        return curr;
    }
    
    int largestBst(Node *root)
    {
        int maxans=0;
        Solution ans=solve(root,maxans);
        return maxans;
    }
};