#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* children[26];
    bool isend=false;
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        int n=word.size();
        Node* node=root;
        for(int i=0;i<n;i++) {
			if(node->children[word[i]-'a']==NULL) {
				node->children[word[i]-'a']=new Node();
			}
			node=node->children[word[i]-'a'];
		}
		node->isend=true;
    }
    
    bool search(string word) {
        int n=word.size();
		Node* node=root;
		for (int i=0;i<n;i++) {
			if (node->children[word[i]-'a']==NULL) {
				return false;
			}
			node=node->children[word[i]-'a'];
		}
		return node->isend;   
	}
    
    bool startsWith(string prefix) {
        int n=prefix.size();
		Node* node=root;
		for (int i=0;i<n;i++) {
			if (node->children[prefix[i]-'a']==NULL) {
				return false;
			}
			node=node->children[prefix[i]-'a'];
		}
		return true;        
    }
};