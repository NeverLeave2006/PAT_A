#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
	int data;
	int flag;
	Node *left;
	Node *right;
};

Node *Insert(Node *root,int data){
	if(root==NULL){
		root=new Node;
		root->data=abs(data);
		root->flag=(data>0);
		root->left=NULL;
		root->right=NULL;
	}else{
		if(abs(data)>root->data){
			root->right=Insert(root->right,data);
		}else{
			root->left=Insert(root->left,data);
		}
	}
	return root;
}

int bn;

void DFS(Node *root,int &res,int numb){
	//printf("%d ",root->data);
	if(root->flag==0){//检查父子两级是否都是红色 
		if(root->left){
			if(root->left->flag==0){
				res=0;
			}
		}
		if(root->right){
			if(root->right->flag==0){
				res=0;
			}
		}
	}
	if(root->left){
		if(root->left->flag==1){
			DFS(root->left,res,numb+1);
		}else{
			DFS(root->left,res,numb);
		}
	}else{//到叶子节点 
		if(bn==-1){
			bn=numb;
		}else{
			if(bn!=numb){
				res=0; 
			} 
		}
	}
	if(root->right){
		if(root->right->flag==1){
			DFS(root->right,res,numb+1);
		}else{
			DFS(root->right,res,numb);
		}
	}else{
		if(bn==-1){
			bn=numb;
		}else{
			if(bn!=numb){
				res=0; 
			} 
		}
	}
}

int main()
{
	int K;
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		int N;
		scanf("%d",&N);
		Node *root=NULL;
		int res=1;
		for(int j=0;j<N;j++){
			int tmp;
			scanf("%d",&tmp);
			root=Insert(root,tmp);
		}
		if(root->flag==0)res=0;
		if(res){
			bn=-1;
			int numb=0;
			DFS(root,res,numb);
			
		}
		printf(res?"Yes\n":"No\n");
	}
	return 0;
}
