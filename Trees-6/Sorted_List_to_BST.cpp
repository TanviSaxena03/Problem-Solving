#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* makeBST(vector<int>&vals,int st,int end){
        TreeNode* root=new TreeNode;
        int m=(st+end)/2;
        if(m-1>=st)
            root->left=makeBST(vals,st,m-1);
        if((m+1)<=end) 
            root->right=makeBST(vals,m+1,end);
        root->val=vals[m];
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL; 
        vector<int>vals;
        while(head){
            vals.push_back(head->val);
            head=head->next;
        }
        int n=vals.size();
        TreeNode* root=makeBST(vals,0,n-1);
        return root;
    }
};