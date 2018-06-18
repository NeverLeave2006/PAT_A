#include <iostream>
#include <vector>
using namespace std;

int N,M;

struct Node{
	int level;
	vector<int> child;
}nn[110]; 

int cnt[101]={0};
int maxlevel=0;

void DFS(int root,int level){
	if(level>maxlevel){
		maxlevel=level;
	}
	nn[root].level=level;
	level++;
	if(nn[root].child.empty()){
		cnt[nn[root].level]++;
	}else{
		for(int i=0;i<nn[root].child.size();i++){
			int idx=nn[root].child[i];
			DFS(idx,level);
		}
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int idx,K;
		scanf("%d%d",&idx,&K);
		for(int i=0;i<K;i++){
			int tmp;
			scanf("%d",&tmp);
			nn[idx].child.push_back(tmp);
		}
	}
	DFS(1,0);
	for(int i=0;i<=maxlevel;i++){
		printf(i?" ":"");
		printf("%d",cnt[i]);
	}
	return 0;
}
