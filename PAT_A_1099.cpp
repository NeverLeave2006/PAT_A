#include <iostream>
#include <algorithm>
#include <queue> 
using namespace std;

int N;
struct Node{
	int data;
	int left;
	int right;
}nn[110];

int data[110],cnt=0,cnt1=0;

void inOrder(int root){
	if(nn[root].left!=-1){
		inOrder(nn[root].left);
	}
	nn[root].data=data[cnt++];
	if(nn[root].right!=-1){
		inOrder(nn[root].right);
	}
}

void levelOrder(int root){
	queue<int> Q;
	Q.push(root);
	while(!Q.empty()){
		int t=Q.front();
		Q.pop();
		printf((cnt1++)?" ":"");
		printf("%d",nn[t].data);
		if(nn[t].left!=-1){
			Q.push(nn[t].left);
		}
		if(nn[t].right!=-1){
			Q.push(nn[t].right);
		}
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		nn[i].left=l;
		nn[i].right=r;
	}
	for(int i=0;i<N;i++){
		scanf("%d",&data[i]);
	}
	sort(data,data+N);
	inOrder(0);
	levelOrder(0);
	return 0;
}
