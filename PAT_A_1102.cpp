#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N,cnt1=0,cnt2=0;

struct Node{
	int data;
	int Left;
	int Right;
}nn[15];

int mark[15]={0};//用于记录节点 

void invert(int root){
	swap(nn[root].Left,nn[root].Right);
	if(nn[root].Left!=-1)
		invert(nn[root].Left);
	if(nn[root].Right!=-1)
		invert(nn[root].Right);
}

void levelOrder(int root){
	queue<int> Q;
	Q.push(root);
	while(!Q.empty()){
		int t=Q.front();
		printf(cnt1?" ":"");
		cnt1++;
		printf("%d",t);
		Q.pop();
		if(nn[t].Left!=-1){
			Q.push(nn[t].Left);
		}
		if(nn[t].Right!=-1){
			Q.push(nn[t].Right);
		}
	}
} 

void inOrder(int root){
	if(nn[root].Left!=-1){
		inOrder(nn[root].Left);
	}
	printf(cnt2?" ":"");
	cnt2++;
	printf("%d",root);
	if(nn[root].Right!=-1){
		inOrder(nn[root].Right);
	}
}

int main()
{
	scanf("%d",&N);
	getchar();
	for(int i=0;i<N;i++){
		nn[i].data=i;
		char c;
		scanf("%c",&c);
		getchar();
		if(c!='-'){
			nn[i].Left=c-'0';
			mark[c-'0']=1;
		}else{
			nn[i].Left=-1;
		}
		scanf("%c",&c);
		getchar();
		if(c!='-'){
			nn[i].Right=c-'0';
			mark[c-'0']=1;
		}else{
			nn[i].Right=-1;
		}
	}
	int root=0;
	for(int i=0;i<N;i++){
		if(!mark[i]){
			root=i;
			break;
		}
	}
	invert(root);
	levelOrder(root);
	printf("\n");
	inOrder(root);	
	return 0;
}
