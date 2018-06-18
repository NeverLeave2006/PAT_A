#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right; 
};

Node *L(Node *a){//左旋 
	Node *r=a->right;
	a->right=r->left;
	r->left=a;
	return r;
}

Node *R(Node *a){//右旋 
	Node *l=a->left;
	a->left=l->right;
	l->right=a;
	return l;
}

int getHeight(Node *root){
	if(root==NULL){
		return 0;
	}
	return max(getHeight(root->left),getHeight(root->right))+1;
}

int dete(Node *root){//正确 
	return getHeight(root->left)-getHeight(root->right);
}

Node *Insert(Node *root,int value){//正确 
	if(root==NULL){
		Node *n=new Node;
		n->data=value;
		n->left=NULL;
		n->right=NULL;
		root=n;
	}else{
		if(value>root->data){
			root->right=Insert(root->right,value);
			int det=dete(root);
			if(det==-2){
				if(dete(root->right)==-1){//未完成！！！！ 
					root=L(root);
				}else if(dete(root->right)==1){
					root->right=R(root->right);
					root=L(root);
				}	
			}
		}else{
			root->left=Insert(root->left,value);
			int det=dete(root);
			if(det==2){
				if(dete(root->left)==1){
					root=R(root);
				}else if(dete(root->left)==-1){
					root->left=L(root->left);
					root=R(root);
				}	
			}
		}
	}
	return root;
}

void DFS(Node *root){//测试函数 
	printf("%d ",root->data);
	if(root->left){
		DFS(root->left);
	}
	if(root->right){
		DFS(root->right);
	}
}
int cnt=0,num[30],cc=0; 
void levOrder(Node *root){
	queue<Node*> Q;
	Q.push(root);
	cnt++;
	int flag=1;
	while(!Q.empty()){
		Node *t=Q.front();
		Q.pop();
		num[cc++]=t->data;
		if(t->left){
			Q.push(t->left);
			if(flag)cnt++;
		}else{
			flag=0;
		}
		if(t->right){
			Q.push(t->right);
			if(flag)cnt++;
		}else{
			flag=0;
		}
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	Node *root=NULL;
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		root=Insert(root,tmp);
		int det=dete(root);
	}
	levOrder(root);
	for(int i=0;i<N;i++){
		printf(i?" ":"");
		printf("%d",num[i]);
	}
	printf(cnt==N?"\nYES":"\nNO");
	return 0;
}
