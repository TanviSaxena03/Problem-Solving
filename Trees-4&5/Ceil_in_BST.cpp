#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int ans=-1;
void find(Node* root, int x) {
    if (root == NULL) return;
    if (root->data==x)
        ans=x;
    else if (root->data<x) 
        find(root->right,x);
    else{
        ans=root->data;
        find(root->left,x);
    }
}

int findCeil(Node* root, int input) {
    find(root,input);
    return ans;
}