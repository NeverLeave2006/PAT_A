#include <iostream>
using  namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *create(Node *root,int data){
	if(root==NULL){
		root=new Node;
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	if(data>root->data){
		root->right=create(root->right,data);
	}else{
		root->left=create(root->left,data);
	}
	return root;
}

int num[1010]={0},lev=0;

void DFS(Node *root,int v){
	num[v]++;
	if(lev<v)lev=v;
	if(root->left!=NULL){
		DFS(root->left,v+1);
	} 
	if(root->right!=NULL){
		DFS(root->right,v+1);
	}
}

int main(){
	int N;
	scanf("%d",&N);
	Node *root=NULL;
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		root=create(root,tmp);
	}
	DFS(root,0);
	printf("%d + %d = %d",num[lev],num[lev-1],num[lev]+num[lev-1]);
	return 0;
}
