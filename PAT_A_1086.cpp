#include <iostream>
#include <stack>
using namespace std;

int N;
int pre[40];
int in[40];

struct Node{
	int Data;
	Node *Left;
	Node *Right;
};

Node *create(int preL,int preR,int inL,int inR){
	if(preL>preR)return NULL;
	Node *root=new Node;
	root->Data=pre[preL];
	int k=inL;
	for(;k<N;k++){
		if(in[k]==pre[preL])break;
	}
	int num=k-inL;
	root->Left=create(preL+1,preL+num,inL,inL+num-1);
	root->Right=create(preL+num+1,preR,inL+num+1,inR);
	return root;
}
int Cnt=0;
void postTra(Node *root){
	if(root->Left)
	postTra(root->Left);
	if(root->Right)
	postTra(root->Right);
	printf(Cnt?" ":"");
	printf("%d",root->Data);
	Cnt+=1;
}

int main()
{
	int cnt1=0,cnt2=0;
	cin>>N;
	stack<int> S;
	for(int i=0;i<N*2;i++){
		string tmp;
		int n;
		cin>>tmp;
		if(tmp=="Push"){
			cin>>n;
			pre[cnt1++]=n;
			S.push(n);
		}else if(tmp=="Pop"){
			in[cnt2++]=S.top();
			S.pop();
		}
	}
	Node *root=create(0,N-1,0,N-1);
	postTra(root);
	return 0;	
} 
