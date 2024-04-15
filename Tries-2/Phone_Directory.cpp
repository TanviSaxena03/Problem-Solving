#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Node {
public:
    char data;
    Node* children[26];
    bool isEnd;
    Node(char ch) {
        data=ch;
        for (int i=0;i<26;i++) {
            children[i]=NULL;
        }
        isEnd=false;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root=new Node('\0');
    }

    void insertUtil(Node* root, string w) {
        if (w.length()==0) {
            root->isEnd=true;
            return;
        }
        int ind=w[0]-'a';
        Node* child;
        if (root->children[ind]!=NULL) {
            child=root->children[ind];
        } else {
            child=new Node(w[0]);
            root->children[ind]=child;
        }
        insertUtil(child,w.substr(1));
    }

    void insert(string word) {
        insertUtil(root,word);
    }

    void printSuggest(Node* curr, vector<string>& temp, string prefix) {
        if (curr->isEnd) {
            temp.push_back(prefix);
        }
        for (char ch='a';ch<='z';ch++) {
            Node* next=curr->children[ch-'a'];
            if (next!=NULL) {
                prefix.push_back(ch);
                printSuggest(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggest(string s) {
        Node* prev=root;
        vector<vector<string>> res;
        string pref="";
        for (int i=0;i<s.length();i++) {
            char lastCh=s[i];
            pref.push_back(lastCh);
            Node* curr=prev->children[lastCh-'a'];
            if (curr==NULL) {
                break;
            }
            vector<string> temp;
            printSuggest(curr,temp,pref);
            res.push_back(temp);
            temp.clear();
            prev=curr;
        }
        int rem=s.size()-res.size();
        for (int i=0;i<rem;i++) {
            res.push_back({"0"});
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        Trie* t=new Trie();
        for (int i=0;i<n;i++) {
            string str=contact[i];
            t->insert(str);
        }
        return t->getSuggest(s);
    }
};