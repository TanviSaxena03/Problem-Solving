#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left;
    Node *right;
	Node(int key){
		data = key;
		left = right = NULL;
	}
};

void printBottomView(Node * root){
	if(!root) return;
	unordered_map<int,int> h; 
	int l=0; 
	queue<pair<Node*,int>> q;
	q.push({root,0}); 
	while(!q.empty()){
		auto top=q.front(); 
		q.pop();
		Node *temp=top.first; 
		int ind=top.second;
		h[ind]=temp->data;
		l=min(ind,l); 
		if(temp->left) q.push({temp->left,ind-1});
		if(temp->right) q.push({temp->right,ind+1});
	}
	while(h.find(l)!=h.end()){ 
        cout<<h[l++]<<" "; 
    }
}

int main(){
	Node *root=new Node(20);
	root->left=new Node(8);
	root->right=new Node(22);
	root->left->left=new Node(5);
	root->left->right=new Node(3);
	root->right->left=new Node(4);
	root->right->right=new Node(25);
	root->left->right->left=new Node(10);
	root->left->right->right=new Node(14);
	printBottomView(root);
	return 0;
}
