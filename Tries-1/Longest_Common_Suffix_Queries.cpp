#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Node{
public:
    bool isEnd=false;
    Node* children[26];
    int ind=INT_MAX;
    int len=INT_MAX;
    Node(){
        for(auto& i:children)
            i=nullptr;
    } 
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root=new Node();
    }

    void insert(string& s,int index){
        Node* node=root;
        for(auto i:s){
            if(node->children[i-'a']==nullptr)
            node->children[i-'a'] =new Node();
            if(s.length()<node->children[i-'a']->len){
                node->children[i-'a']->len=s.length();
                node->children[i-'a']->ind=index;
            }
            node=node->children[i-'a'];
        }
        node->isEnd=true;
    }

    int search(string& word){
        Node* node=root;
        for(auto i:word){
            if(node->children[i-'a']==nullptr) return node->ind;
            node=node->children[i-'a'];
        }
        return node->ind;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* trie=new Trie();
        int mn=INT_MAX;
        int index=-1;
        for(int i=0;i<wordsContainer.size();i++){
            reverse(wordsContainer[i].begin(),wordsContainer[i].end());
            if(wordsContainer[i].length()<mn){
                mn=wordsContainer[i].length();
                index=i;
            }
            trie->insert(wordsContainer[i],i);
        }
        vector<int>ans(wordsQuery.size(),-1);
        for(int i=0;i<wordsQuery.size();i++){
            reverse(wordsQuery[i].begin(),wordsQuery[i].end());
            int t=trie->search(wordsQuery[i]);
            ans[i]=t==INT_MAX?index:t;
        }
        return ans;
    }
};