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
    TreeNode* lca(TreeNode* root, int p, int q){
        if(!root or p==root->val or q==root->val) return root;
        TreeNode* l=lca(root->left,p,q);
        TreeNode* r=lca(root->right,p,q);
        if(!l) return r;
        if(!r) return l;
        return root;
    }
    string t="";
    bool flag=false;
    void dfs(TreeNode* root,int node,char ch,string &s){
        if(!root) return;
        if(root->val==node){
            if(ch!='#') s+=ch;
            t=s;
            flag=true;
            return;
        }
        if(ch!='#') s+=ch;
        dfs(root->left,node,'L',s);
        dfs(root->right,node,'R',s);
        s.pop_back();
    }
    string getDirections(TreeNode* root, int st, int des) {
        TreeNode* start=lca(root,st,des);
        string s="";
        dfs(start,des,'#',s);
        string temp=t;
        s.clear();
        dfs(start,st,'#',s);
        string ans="";
        for(int i=0;i<t.size();i++) ans+='U';
        ans+=temp;
        cout<<temp<<" "<<t<<endl;
        return ans;
    }
};