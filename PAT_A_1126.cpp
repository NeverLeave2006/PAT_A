#include <iostream>
#include <vector>
using namespace std;

int N,M;
int deg[510]={0},inq[510]={0};
int cnt=0,cntN=0;

vector<int> vi[510];

void DFS(int root){
	inq[root]=1;
	cntN++;
	for(int i=0;i<vi[root].size();i++){
		if(inq[vi[root][i]]==0){
			DFS(vi[root][i]);
		}
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		deg[a]++;
		deg[b]++;
		vi[a].push_back(b);
		vi[b].push_back(a);
	}
	for(int i=1;i<=N;i++){
		printf(i!=1?" ":"");
		printf("%d",deg[i]);
		if(deg[i]%2)cnt++;
	}
	printf("\n");
	DFS(1);
	if(cntN==N){
		if(cnt==0)printf("Eulerian");
		else{
			if(cnt==2){
				printf("Semi-Eulerian");
			}else{
				printf("Non-Eulerian");
			} 
		}
	}else{
		printf("Non-Eulerian");
	}
	return 0;
}
