#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define maxv 210
#define inf 1000000000
using namespace std;

int N,K,happy[maxv],vis[maxv],d[maxv];
string start;
map<string,int> s2i;
map<int,string> i2s;
int cost[maxv][maxv];
vector<int> pre[maxv];

void Dijkstra(){
	while(!vis[s2i["ROM"]]){
		int u=-1,length=inf;
		for(int i=0;i<N;i++){
			if(d[i]<length&&!vis[i]){
				u=i;
				length=d[i];
			}
		}
		if(u==-1)return;
		vis[u]=1;
		for(int i=0;i<N;i++){
			if(d[u]+cost[u][i]<=d[i]){
				if(d[u]+cost[u][i]<d[i]){
					pre[i].clear();
					d[i]=d[u]+cost[u][i];
					pre[i].push_back(u);
				}else if(d[u]+cost[u][i]==d[i]&&d[i]!=inf){
					pre[i].push_back(u);
				}
				
			}
		}
	}
}
vector<int> trace,tmptrace;
int minh=-1,tmph=0,cc=0,avgh=0;

void DFS(int root){
	if(i2s[root]==start){
		cc++;
		if(tmph>minh){
			minh=tmph;
			trace=tmptrace;
			avgh=minh/(tmptrace.size()-1);
		}else if(tmph==minh&&(tmph/(tmptrace.size()-1))>avgh){
			trace=tmptrace;
			avgh=minh/(tmptrace.size()-1);
		}
		return;
	}
	for(int i=0;i<pre[root].size();i++){
		cc+=cost[root][pre[root][i]];
		tmph+=happy[pre[root][i]];
		tmptrace.push_back(pre[root][i]);
		DFS(pre[root][i]);
		tmptrace.pop_back();
		tmph-=happy[pre[root][i]];
		cc-=cost[root][pre[root][i]];
	}
}

int main()
{
	scanf("%d%d",&N,&K);
	cin>>start;
	s2i[start]=0;
	i2s[0]=start;
	happy[0]=0;
	fill(cost[0],cost[0]+maxv*maxv,inf);
	for(int i=1;i<N;i++){
		string tmp;
		int happiness;
		cin>>tmp>>happiness;
		s2i[tmp]=i;
		i2s[i]=tmp;
		happy[i]=happiness;
	}
	for(int i=0;i<K;i++){
		string a,b;
		int Cost;
		cin>>a>>b>>Cost;
		cost[s2i[a]][s2i[b]]=Cost;
		cost[s2i[b]][s2i[a]]=Cost;
	}
	fill(vis,vis+maxv,0);
	fill(d,d+maxv,inf);
	
	d[0]=0;
	Dijkstra();
//	for(int i=0;i<N;i++){
//		printf("%d ",d[i]);
//	}

	int des=s2i["ROM"];
	tmptrace.push_back(s2i["ROM"]);
	cc=0;
	tmph=happy[s2i["ROM"]];
	DFS(s2i["ROM"]);
	printf("%d %d %d %d",cc,d[s2i["ROM"]],minh,avgh);
	reverse(trace.begin(),trace.end());
	printf("\n");
	for(int i=0;i<trace.size();i++){
		printf(i?"->":"");
		cout<< i2s[trace[i]];
	}
	return 0;
}
