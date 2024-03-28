#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
bool find(TreeNode *t, int x, vector<int>& v) {
    if(t==NULL)    
        return 0;
    bool f=0;
    if (t->val==x||find(t->left,x,v)||find(t->right,x,v))
        f=1,
        v.push_back(t->val);
    return f;
}
    
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> v;
    bool f=find(A,B,v);
    reverse(v.begin(),v.end());
    return v;
}