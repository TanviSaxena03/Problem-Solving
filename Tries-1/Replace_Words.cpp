#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct Node{
    Node* children[26];
    bool isEnd=false;
};

class Solution {
private:
    Node *root;

public:
    Solution() {
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
		node->isEnd=true;
    }

    string check(string word){
        Node *t=root;
        string s="";       
        for(auto i:word){
            if(!t->children[i-'a']) break;
            s+=i;
            t=t->children[i-'a'];
            if(t->isEnd) return s;
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        root=new Node();
        for(auto s:dictionary) insert(s);
        istringstream ss(sentence);
        string word="", ans="";
        
        for(;ss>>word;){
            ans+=check(word);
            ans+=' ';
        }
        ans.pop_back();
        
        return ans;        
    }
};