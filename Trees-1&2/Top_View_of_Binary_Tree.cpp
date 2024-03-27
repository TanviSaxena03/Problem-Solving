#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int>topn;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            Node* fr=temp.first;
            int hd=temp.second;
            if(topn.find(hd)==topn.end())
               topn[hd]=fr->data;
            if(fr->left)
              q.push(make_pair(fr->left,hd-1));
            if(fr->right)
              q.push(make_pair(fr->right,hd+1));
        }
        for(auto i:topn){
            ans.push_back(i.second);
        }
        return ans;
    }
};