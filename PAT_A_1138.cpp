#include <iostream>

using namespace std;

int N;
int pre[50010],in[50010];

struct Node{
	int data;
	Node *left;
	Node *right;
};

int cnt=0,post[50010];

Node *create(int preL,int preR,int inL,int inR){
	if(preL>preR)return NULL;
	Node *a=new Node;
	int k=inL;
	for(;k<N;k++){
		if(in[k]==pre[preL]){
			break;
		}
	}
	int num=k-inL;
	a->left=create(preL+1,preL+num,inL,k-1);
	a->right=create(preL+num+1,preR,k+1,inR);
	a->data=pre[preL];
	post[cnt++]=pre[preL];//标记后续序列！！！！ 
	return a;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&in[i]);
	}
	Node *a=create(0,N-1,0,N-1);
	printf("%d",post[0]);
	return 0;
}
