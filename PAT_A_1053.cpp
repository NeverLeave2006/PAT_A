#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int weight;
	vector<int> next;
}nn[110];

bool cmp(int a,int b){
	return nn[a].weight>nn[b].weight;
}

int path[110]={0};

int N,M,S; 

void DFS(int index,int sum,int cnt){
	
	if(sum>S)return;
	if(sum==S&&nn[index].next.empty()){
		for(int i=0;i<cnt;i++){
			printf(i?" ":"");
			printf("%d",path[i]);
		}
		printf("\n");
	}
	if(sum<S){
		if(nn[index].next.empty())return;
		for(int i=0;i<nn[index].next.size();i++){
			int nextindex=nn[index].next[i];
			path[cnt]=nn[nextindex].weight;
			DFS(nextindex,sum+nn[nextindex].weight,cnt+1);
		}
	}
}

int main()
{
	scanf("%d%d%d",&N,&M,&S);
	for(int i=0;i<N;i++){
		scanf("%d",&nn[i].weight); 
	}
	for(int i=0;i<M;i++){
		int index,n;
		scanf("%d%d",&index,&n);
		for(int j=0;j<n;j++){
			int tmp;
			scanf("%d",&tmp);
			nn[index].next.push_back(tmp);
		}
		sort(nn[index].next.begin(),nn[index].next.end(),cmp);
	}
	path[0]=nn[0].weight;
	DFS(00,nn[0].weight,1);
	return 0;
}
