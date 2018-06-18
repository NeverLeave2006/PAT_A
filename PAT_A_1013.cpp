#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M,K;
vector<int> v[1010];
int checked[1010];

void BFS(int city){
	queue<int> Q;
	Q.push(city);
	while(Q.size()){
		int t=Q.front();
		Q.pop();
		for(int i=0;i<v[t].size();i++){
			if(!checked[v[t][i]]){
				Q.push(v[t][i]);
				checked[v[t][i]]=1;
			}
		}
	}
}

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=0;i<K;i++){
		int c;
		scanf("%d",&c);
		int cnt=0;
		fill(checked,checked+N+1,0);
		checked[c]=1;
		for(int i=1;i<=N;i++){
			if(!checked[i]){
				BFS(i);
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
	}
	return 0;
}
