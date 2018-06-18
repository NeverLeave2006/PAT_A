#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#define INT_MAX 2147483647 
using namespace std;

int N,M,C1,C2;

struct Road{
	int des,length;
};

vector<Road> c[510];
int amount[510],vis[510],dis[510],ways[510],w[510];
set<int> si;

int Max=0;

void Dijkstra(){
	while(!vis[C2]){
		int u=-1,length=INT_MAX;//找到最小路径 
		for(int i=0;i<N;i++){
			if(dis[i]<length&&vis[i]==0){
				u=i;
				length=dis[i];
			}
		}
		if(u!=-1){
			vector<Road> r=c[u];
			vis[u]=1;
			for(int i=0;i<c[u].size();i++){
				Road rr=r[i];
				if((rr.length+dis[u])<=dis[rr.des]){
					dis[rr.des]=rr.length+dis[u];
					if((rr.length+dis[u])<dis[rr.des]){
						ways[rr.des]=ways[u];
						w[rr.des]=w[u]+amount[rr.des];
					}else{
						ways[rr.des]+=ways[u];
						if(w[u]+amount[rr.des]>w[rr.des]){
							w[rr.des]=w[u]+amount[rr.des];
						}
					}
					
					
				}
			}
		}else{
			break;
		}
	}
}

int main()
{
	scanf("%d%d%d%d",&N,&M,&C1,&C2);
	for(int i=0;i<N;i++){
		scanf("%d",&amount[i]);
	}
	for(int i=0;i<M;i++){
		int c1,c2,length;
		scanf("%d%d%d",&c1,&c2,&length);
		Road r1;
		r1.des=c2;
		r1.length=length;
		c[c1].push_back(r1);
		Road r2;
		r2.des=c1;
		r2.length=length;
		c[c2].push_back(r2);
	}
	for(int i=0;i<N;i++){
		dis[i]=INT_MAX;
		vis[i]=0;
		ways[510]=0;
		
	}
	dis[C1]=0;
	ways[C1]=1;
	w[C1]=amount[C1];
	Dijkstra();
	int sum=0;
	for(set<int>::iterator it=si.begin();it!=si.end();it++){
		sum+=amount[*it];
	}
	printf("%d %d",ways[C2],w[C2]);
	return 0;
}
