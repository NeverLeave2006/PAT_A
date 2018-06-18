#include <iostream>

using namespace std;

struct Node{
	string data;
	int left,right;
}nn[30];

int N;
int F[30]={0};
int tt;

int getHeight(int root){
	if(root==-1)return 0;
	return max(getHeight(nn[root].left),getHeight(nn[root].right))+1;
}

void DFS(int root){
	if(nn[root].left!=-1){
		DFS(nn[root].left);
	}
	if(nn[root].right!=-1){
		DFS(nn[root].right);
	}
	if(getHeight(root)==2){
		string s="";
		if(root!=tt)s+="(";
		if(nn[root].left!=-1)s+=nn[nn[root].left].data;
		s+=nn[root].data;
		if(nn[root].right!=-1)s+=nn[nn[root].right].data;
		if(root!=tt)s+=")";
		nn[root].left=-1;
		nn[root].right=-1;
		nn[root].data=s;
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		cin>>nn[i].data>>nn[i].left>>nn[i].right;
		if(nn[i].left!=-1){
			F[nn[i].left]=1;
		}
		if(nn[i].right!=-1){
			F[nn[i].right]=1;
		}
	}
	int root;
	for(root=1;root<=N;root++){
		if(!F[root]){
			break;
		}
	}
	tt=root;
	DFS(root);
	cout<<nn[root].data;
	
	return 0;
 } 
