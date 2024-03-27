#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Solution{
  public:
    int getLevelDiff(Node *root){
        queue<Node*>q;
        q.push(root);
        bool isOdd=true;
        int o=0;
        int e=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node*curr=q.front();
                q.pop();
                if(isOdd)
                    o+=curr->data;
                else
                    e+=curr->data;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            isOdd=!isOdd;
        }
        return o-e;
    }
};