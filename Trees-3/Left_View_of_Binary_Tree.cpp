#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct BinaryTreeNode {
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()){
        vector<BinaryTreeNode<int>*> ln;
        int n = q.size();
        for (int i = 0; i < n; i++) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            ln.push_back(node);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        if(!ln.empty()){
            ans.push_back(ln[0]->data);
        }
    }
    return ans;
}