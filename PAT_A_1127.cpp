#include <iostream>
#include <stack>
using namespace std;

int N;
int in[40],post[40];

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *create(int inL,int inR,int postL,int postR){
	if(inL>inR){
		return NULL;
	}
	Node *root=new Node;
	root->data=post[postR];
	int k=inL;
	for(;k<=inR;k++){
		if(in[k]==post[postR]){
			break;
		}
	}
	int num=k-inL;
	root->left=create(inL,k-1,postL,postL+num-1);
	root->right=create(k+1,inR,postL+num,postR-1);
	return root;
}
void Zig(Node *root){
	stack<Node*> a,b;
	a.push(root);
	printf("%d",root->data);
	while(!a.empty()||!b.empty()){
		while(!a.empty()){
			Node *t=a.top();
			a.pop();
			if(t->left){
				printf(" %d",t->left->data);
				b.push(t->left);
			}
			if(t->right){
				printf(" %d",t->right->data);
				b.push(t->right);
			}
		}
		while(!b.empty()){
			Node *t=b.top();
			b.pop();
			if(t->right){
				printf(" %d",t->right->data);
				a.push(t->right);
			}
			if(t->left){
				printf(" %d",t->left->data);
				a.push(t->left);
			}
		}
	}
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&in[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&post[i]);
	}
	Node *root=create(0,N-1,0,N-1);
	Zig(root);
	return 0;
}
