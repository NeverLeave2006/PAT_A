#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v[10010];
int vis[10010]={0};
int nn[10010]={0};


int maxH,result=0;
void DFS(int root,int height){
	vis[root]++;
	if(maxH<height){
		maxH=height;
	}
	for(int i=0;i<v[root].size();i++){
		if(vis[v[root][i]]==0){
			DFS(v[root][i],height+1);
		}
	}
}

bool isTree(){
	for(int i=1;i<=N;i++){
		if(vis[i]!=1){
			return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int cnt=0,maxleval;
	DFS(1,0);
	if(!isTree()){
		fill(vis+1,vis+N+1,0);
		for(int i=1;i<=N;i++){
			if(vis[i]==0){
				DFS(i,0);
				cnt++;
			}
		}
		printf("Error: %d components\n",cnt);		
	}else{
		for(int i=1;i<=N;i++){
			fill(vis+1,vis+N+1,0);
			if(v[i].size()==1&&vis[i]==0){
				maxH=0;
				DFS(i,0);
				if(result<maxH){
					result=maxH;
				}
				nn[i]=maxH;
			}
		}
		for(int i=1;i<=N;i++){
			if(nn[i]==result){
				printf("%d\n",i);
			}
		}
	}
	
	
	return 0;
}
