#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct Node { 
    Node *child[2];    
    int cnt; 
    Node() { 
        child[0]=child[1]=NULL; 
        cnt=0; 
    } 
};

void insert(Node *root, int n) { 
    for (int i=16;i>=0;i--) { 
        bool x=(n)&(1<<i); 
        if(!root->child[x]) { 
            root->child[x]=new Node(); 
        }  
        root->child[x]->cnt+=1; 
        root=root->child[x]; 
    } 
}

class Solution {
private:
    int SmallerPairs(Node *root,  int n, int k) { 
        int cntPairs=0; 
        for (int i=16;i>=0&&root;i--) {                 
            bool x=n&(1<<i); 
            bool y=k&(1<<i); 
            if (y==0) { 
                root=root->child[x]; 
                continue;
            } 
            if(root->child[x]) {
                cntPairs+=root->child[x]->cnt; 
            }
            root=root->child[1-x]; 
        } 
        return cntPairs; 
    }

public:
    int countPairs(vector<int>& nums, int low, int high) {
        Node* root=new Node();       
        int cnt=0;
        for (auto& num:nums) {
            cnt+=SmallerPairs(root,num,high+1)-SmallerPairs(root,num,low);
            insert(root,num);
        }        
        return cnt;        
    }
};