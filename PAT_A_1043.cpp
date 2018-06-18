#include <iostream>
#include <vector>
using namespace std;

int N,cnt=1;
vector<int> ori,pre,preM,post,postM;
struct Node{
	int data;
	int left;
	int right;
}nn[1010];

void init(){//≥ı ºªØ 
	for(int i=0;i<1010;i++){
		nn[i].data=-1;
		nn[i].left=-1;
		nn[i].right=-1;
	}
}

void Push(int root,int data){
	if(nn[root].data==-1)
		nn[root].data=data;
	else{
		if(data<nn[root].data){
			if(nn[root].left==-1)nn[root].left=cnt++;
			Push(nn[root].left,data);
		}else{
			if(nn[root].right==-1)nn[root].right=cnt++;
			Push(nn[root].right,data);
		}
			
	}
}

void PreTra(int root){
	pre.push_back(nn[root].data);
	if(nn[root].left!=-1){
		PreTra(nn[root].left);
	}
	if(nn[root].right!=-1){
		PreTra(nn[root].right);
	}
}

void PreTraMirr(int root){
	preM.push_back(nn[root].data);
	if(nn[root].right!=-1){
		PreTraMirr(nn[root].right);
	}
	if(nn[root].left!=-1){
		PreTraMirr(nn[root].left);
	}
}

void PostTra(int root){
	if(nn[root].left!=-1){
		PostTra(nn[root].left);
	}
	if(nn[root].right!=-1){
		PostTra(nn[root].right);
	}
	post.push_back(nn[root].data);
}

void PostTraMirr(int root){
	
	if(nn[root].right!=-1){
		PostTraMirr(nn[root].right);
	}
	if(nn[root].left!=-1){
		PostTraMirr(nn[root].left);
	}
	postM.push_back(nn[root].data);
}

int main()
{
	init();
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		ori.push_back(tmp);
		Push(0,tmp);
	}
	PreTra(0);
	PreTraMirr(0);
	PostTra(0);
	PostTraMirr(0);
	if(ori==pre){
		printf("YES\n");
		for(int i=0;i<post.size();i++){
			printf(i?" ":"");
			printf("%d",post[i]);
		}
	}else if(ori==preM){
		printf("YES\n");
		for(int i=0;i<postM.size();i++){
			printf(i?" ":"");
			printf("%d",postM[i]);
		}
	}else{
		printf("NO");
	}
	return 0;
}
