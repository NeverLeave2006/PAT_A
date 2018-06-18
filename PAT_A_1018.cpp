#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Cmax,N,Sp,M;
int d[510],vis[510]={0},amount[510];
struct Road{
	int dest;
	int time;
};

vector<Road> S[510];
vector<int> pre[510];

void Dijkstra(){
	while(vis[Sp]==0){
		int u=-1,length=1000000000;
		for(int i=0;i<N;i++){
			if(!vis[i]&&length>d[i]){
				u=i;
				length=d[i];
			}
		}
		if(u==-1)break;
		vis[u]=1;
		vector<Road> ss=S[u];
		for(int i=0;i<ss.size();i++){
			if(d[ss[i].dest]>=d[u]+ss[i].time){
				if(d[ss[i].dest]>d[u]+ss[i].time){
					pre[ss[i].dest].clear();
				}
				d[ss[i].dest]=d[u]+ss[i].time;
				pre[ss[i].dest].push_back(u);
			}
		}
	}
}

vector<int> trace,tmptrace;
int minNeed=1000000000,minBack=1000000000;

void DFS(int root){
	tmptrace.push_back(root);
	if(root==0){
		int need=0,back=0;
		for(int i=tmptrace.size()-1;i>=0;i--){
			int id=tmptrace[i];
			if(amount[id]>0){
				back+=amount[id];
			}else{
				if(back+amount[id]>0){
					back+=amount[id];
				}else{
					need+=-(back+amount[id]);
					back=0;
				}
			}
		}
		if(need<minNeed){
			minNeed=need;
			minBack=back;
			trace=tmptrace;
		}else if(need==minNeed&&back<minBack){
			minBack=back;
			trace=tmptrace;
		}
		tmptrace.pop_back();
		return;
	}
	for(int i=0;i<pre[root].size();i++){
		DFS(pre[root][i]);
	}
	tmptrace.pop_back();
}

int main()
{
	scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
	for(int i=1;i<=N;i++){
		scanf("%d",&amount[i]);
		amount[i]-=(Cmax/2);
	}
	for(int i=0;i<M;i++){
		int Si,Sj,T;
		scanf("%d%d%d",&Si,&Sj,&T);
		Road r1,r2;
		r1.dest=Sj;
		r1.time=T;
		r2.dest=Si;
		r2.time=T;
		S[Si].push_back(r1);
		S[Sj].push_back(r2);
	}
	fill(d,d+N+1,1000000000);
	d[0]=0;
	
	Dijkstra();
	trace.push_back(Sp);
	DFS(Sp);
	printf("%d 0",minNeed);
	for(int i=trace.size()-2;i>=0;i--){
		printf("->%d",trace[i]);
	}
	printf(" %d",minBack);
	return 0;
} 
