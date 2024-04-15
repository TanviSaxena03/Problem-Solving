#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Node {
public:
    int numOfInd;
    int sumOfInd;
    Node* child[2];
    
    Node():numOfInd(0),sumOfInd(0) {
        child[0]=NULL;
        child[1]=NULL;
    }
};

class Solution {
public:
    void addNum(Node* root, int num, int idx){
        for( int i=31;i>=0;i--){
            int bit=1&(num>>i);
            if (root->child[bit]==NULL){
                root->child[bit]=new Node();
            }
            root = root->child[bit];
        }
        root->sumOfInd+=idx;
        root->numOfInd++;
    }

    int calcPair(Node* root, int num, int idx){
        for(int i=31;i>=0;i--){
            int bit=1&(num>>i);
            if (root->child[bit]==NULL){
                return 0;
            }
            root = root->child[bit];
        }
        return (((root->numOfInd)*idx)-(root->sumOfInd));
    }

    int countTriplets(vector<int>& arr) {
        long long ans=0;
        int XOR=0;
        Node* root=new Node();
        for (int i=0;i<arr.size();i++){
            addNum(root,XOR,i);
            XOR^=arr[i];
            ans=(ans+calcPair(root,XOR,i))%1000000007;
        }
        return ans;   
    }
};