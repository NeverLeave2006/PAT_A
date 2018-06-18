#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,S,D,vis[510]={0},d[510];
struct Road{
	int dest,dis,cost;
};
vector<Road> C[510];
vector<int> pre[510];

void Dijkstra(){
	while(!vis[D]){
		int u=-1,length=1000000000;
		for(int i=0;i<N;i++){
			if(!vis[i]&&d[i]<length){
				u=i;
				length=d[i];
			}
		}
		if(u==-1){
			break;
		}
		vector<Road> city=C[u];
		vis[u]=1;
		for(int i=0;i<city.size();i++){
			if(d[u]+city[i].dis<d[city[i].dest]){
				d[city[i].dest]=d[u]+city[i].dis;
				pre[city[i].dest].clear();
				pre[city[i].dest].push_back(u);
			}else if(d[u]+city[i].dis==d[city[i].dest]){
				pre[city[i].dest].push_back(u);
			} 
		}
	}
}

vector<int> trace,tmptrace;
int Totolcost=2147483647,tmpcost=0;

void DFS(int root){
	if(root==S){
		if(Totolcost>tmpcost){
			Totolcost=tmpcost;
			trace=tmptrace;
		}
		return;
	}
	//printf("%d ",root);
	for(int i=0;i<pre[root].size();i++){
		tmptrace.push_back(pre[root][i]);
		int cost;
		for(int j=0;j<C[pre[root][i]].size();j++){
			if(C[pre[root][i]][j].dest==root){
				cost=C[pre[root][i]][j].cost;
			}
		}
		tmpcost+=cost;
		DFS(pre[root][i]);
		tmpcost-=cost;
		tmptrace.pop_back();
	}
}

int main()
{
	scanf("%d%d%d%d",&N,&M,&S,&D);
	for(int i=0;i<M;i++){
		int c1,c2,dis,cost;
		scanf("%d%d%d%d",&c1,&c2,&dis,&cost);
		Road r1,r2;
		r1.dest=c2;
		r1.dis=dis;
		r1.cost=cost;
		C[c1].push_back(r1);
		r2.dest=c1;
		r2.dis=dis;
		r2.cost=cost;
		C[c2].push_back(r2);
	}
	fill(vis,vis+N,0);
	fill(d,d+N,1000000000);
	d[S]=0;
	Dijkstra();
	tmptrace.push_back(D);
	DFS(D);
	reverse(trace.begin(),trace.end());
	for(int i=0;i<trace.size();i++){
		printf("%d ",trace[i]);
	}
	printf("%d %d",d[D],Totolcost);
	return 0;
}
