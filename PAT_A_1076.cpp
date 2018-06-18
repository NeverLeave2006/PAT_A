#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,L;
struct Node{
	int layer;
	vector<int> vv;
}v[1010];

int inq[1010]={0};

void BFS(int node,int &cnt){
	cnt=0;
	queue<int> Q;
	Q.push(node);
	inq[node]=1;
	v[node].layer=0;
	while(!Q.empty()){
		int t=Q.front();
		Q.pop();
		for(int i=0;i<v[t].vv.size();i++){
			if(!inq[v[t].vv[i]]){
				v[v[t].vv[i]].layer=v[t].layer+1;
				Q.push(v[t].vv[i]);
				inq[v[t].vv[i]]=1;
			}
			
		}
		if(v[t].layer<=L&&v[t].layer!=0){
			cnt++;
		}
	}
}

int main()
{
	scanf("%d%d",&N,&L);
	for(int i=1;i<=N;i++){
		int m;
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			int tmp;
			scanf("%d",&tmp);
			v[tmp].vv.push_back(i);
		}
	}
	int K;
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		int ques;
		scanf("%d",&ques);
		int cnt=0;
		fill(inq,inq+N+1,0);
		BFS(ques,cnt);
		printf("%d\n",cnt);
	}
	return 0;
}
