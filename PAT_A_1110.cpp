#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node{
	int left;
	int right;
}nn[110];

int rr[110]={0};

int N,cnt=0,flag=1,last,pre;

void levelOrder(int root){
	queue<int> Q;
	Q.push(root);
	cnt++;
	while(!Q.empty()){
		int t=Q.front();
		Q.pop();
		if(nn[t].left!=-1){
			Q.push(nn[t].left);
			pre=nn[t].left;
			if(flag)cnt++;
		}else{
			flag=0;
			break;
		}
		if(nn[t].right!=-1){
			Q.push(nn[t].right);
			pre=nn[t].right;
			if(flag)cnt++;
		}else{
			flag=0;
			break;
		}
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		string a,b;
		cin>>a>>b;
		if(a!="-"){
			nn[i].left=stoi(a);
			rr[stoi(a)]=1;
		}else{
			nn[i].left=-1;
		}
		if(b!="-"){
			nn[i].right=stoi(b);
			rr[stoi(b)]=1;
		}else{
			nn[i].right=-1;
		}
	}
	int root;
	for(int i=0;i<N;i++){
		if(rr[i]==0){
			root=i;
			break;
		}
	}
	levelOrder(root);
	if(cnt==N){
		printf("YES %d",pre);
	}else{
		printf("NO %d",root);
	}
	return 0;
}
