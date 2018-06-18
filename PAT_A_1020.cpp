#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int data;
	Node *Left;
	Node *Right;
};

int post[40];
int in[40];

Node *create(int postL,int postR,int inL,int inR){
	if(postR<postL){
		return NULL;
	}
	Node *root=new Node;
	root->data=post[postR];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==post[postR])break;
	}
	int num=k-inL;
	root->Left=create(postL,postL+num-1,inL,k-1);
	root->Right=create(postL+num,postR-1,k+1,inR);
	return root;
}

void BFS(Node *root){
	queue<Node *> Q;
	Q.push(root);
	int num=0;
	while(!Q.empty()){
		Node* t=Q.front();
		if(num)printf(" ");
		printf("%d",t->data);
		num++;
		Q.pop();
		if(t->Left){
			Q.push(t->Left);
		}
		if(t->Right){
			Q.push(t->Right);
		}
	} 
} 

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&in[i]);
	}
	Node *root=create(0,N-1,0,N-1);
	BFS(root);
	return 0;
} 
