#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int val;
	int left;
	int right;
	int height;
}nn[30];

int N,cnt=0;

int init(){//≥ı ºªØ 
	for(int i=0;i<30;i++){
		nn[i].left=-1;
		nn[i].right=-1;
	}
}

int updateHeight(int root){
	if(root==-1){
		return 0;
	}else{
		int tmp= max(updateHeight(nn[root].left),updateHeight(nn[root].right))+1;
		nn[root].height=tmp;
		return tmp;
	}
}

void L(int &root){
	int r=nn[root].right;
	nn[root].right=nn[r].left;
	nn[r].left=root;
	updateHeight(root);
	updateHeight(r);
	root=r;	
}

void R(int &root){
	int l=nn[root].left;
	nn[root].left=nn[l].right;
	nn[l].right=root;
	updateHeight(root);
	updateHeight(l);
	root=l;
}


int getBalanceFac(int root){
	int l=nn[root].left,r=nn[root].right;
	int hl,hr;
	if(l==-1)hl=0;
	else{
		hl=nn[l].height;
	}
	if(r==-1)hr=0;
	else{
		hr=nn[r].height;
	}
	return hl-hr;
}

void Insert(int &root,int x){
	if(cnt==0){
		nn[cnt++].val=x;
		return;
	}
	if(x<nn[root].val){
		if(nn[root].left!=-1){
			Insert(nn[root].left,x);
		}else{
			nn[root].left=cnt++;
			nn[nn[root].left].val=x;
		}
		updateHeight(root);
		if(getBalanceFac(root)==2){
			if(getBalanceFac(nn[root].left)==1){
				R(root);
			}else if(getBalanceFac(nn[root].left)==-1){
				L(nn[root].left);
				R(root);
			}
		}
	}else{
		if(nn[root].right!=-1){
			Insert(nn[root].right,x);
		}else{
			nn[root].right=cnt++;
			nn[nn[root].right].val=x;
		}
		updateHeight(root);
		if(getBalanceFac(root)==-2){
			if(getBalanceFac(nn[root].right)==-1){
				L(root);
			}else if(getBalanceFac(nn[root].right)==1){
				R(nn[root].right);
				L(root);
			}
		}
	}
	
	//
}

int main()
{
	init();
	scanf("%d",&N);
	int root=0;
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		Insert(root,tmp);
		
	}
	printf("%d",nn[root].val);
	return 0;
}
