#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct Trie{
    Trie *children[256]={nullptr};
    unordered_set<string> words;
    Trie(){
    }
};

struct cmp{
    bool operator()(pair<int,string> &a, pair<int,string> &b){
        if(a.first==b.first){
            string temp1=a.second, temp2=b.second;
            int result=temp1.compare(temp2);
        return result<0;
        }
    return a.first>b.first;
    }
};

class AutoCompleteSystem {
private:
    Trie* root;
    string curr="";
    unordered_map<string,int> mp;
    priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
    
public:
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times){
        root=new Trie();
        for(int i=0;i<sentences.size();i++){
            insert(sentences[i]);
            mp[sentences[i]]=times[i];
        }
    }
    
    void insert(string &str){
        Trie* pcrawl=root;
        for(auto ch : str){
            if(pcrawl->children[ch]==NULL){
                pcrawl->children[ch]=new Trie();
            }
            pcrawl=pcrawl->children[ch];
            (pcrawl->words).insert(str);
            
        }
        (pcrawl->words).insert(str);
    }
    
    vector<string> input(char ch) {
        if(ch=='#'){
            insert(curr);
            mp[curr]++;
            curr="";
        return {};
        }
        vector<string> res;
        curr+=ch;
        Trie *ptr=root;
        int i=0;
        while(i<curr.size() and ptr->children[curr[i]]!=NULL){
            ptr=ptr->children[curr[i]];
            i++;
        }
        if(i==curr.size()){
            unordered_set<string> st=ptr->words;
            for(auto it : st){
                pq.push({mp[it],it});
                if(pq.size()>3){
                    pq.pop();
                }
            }
            while(!pq.empty()){
                res.push_back(pq.top().second);
                pq.pop();
            }
            reverse(res.begin(),res.end());
        }
    return res;
    }
};