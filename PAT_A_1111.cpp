#include <iostream>
#include <vector>
using namespace std;
int n,m,src,dest,inf=999999999;
int pre1[510],pre2[510],length[510][510],Time[510][510],visit[510]={0},dis[510],dislength,distime;
vector<int> timepath,lengthpath,path;
int totaltime=0,totallength=0,finaltime=inf,finallength=inf,weight[510],NodeNum[510];
void dfs1(int v){
	lengthpath.push_back(v);
	if(v==src)return;
	dfs1(pre1[v]);
}
void dfs2(int v){
	timepath.push_back(v);
	if(v==src)return;
	dfs2(pre2[v]);
}
int main()
{
	scanf("%d%d",&n,&m);
	fill(length[0],length[0]+510*510,inf);
	fill(Time[0],Time[0]+510*510,inf);
	for(int i=0;i<m;i++){
		int v1,v2,ow,len,t;
		scanf("%d%d%d%d%d",&v1,&v2,&ow,&len,&t);
		length[v1][v2]=len;
		Time[v1][v2]=t;
		if(!ow){
			length[v2][v1]=len;
			Time[v2][v1]=t;
		}
	}
	scanf("%d%d",&src,&dest);
	fill(dis,dis+510,inf);
	fill(visit,visit+510,0);
	fill(weight,weight+510,0); 
	pre1[src]=src;
	dis[src]=0;
	for(int i=0;i<n;i++){
		int u=-1,minn=inf;
		for(int t=0;t<n;t++){
			if(!visit[t]&&dis[t]<minn){
				u=t;
				minn=dis[u];
			}
		}
		if(u==-1)break;
		visit[u]=1;
		for(int v=0;v<n;v++){
			if(!visit[v]&&length[u][v]!=inf){
				if(dis[v]>dis[u]+length[u][v]){
					dis[v]=dis[u]+length[u][v];
					pre1[v]=u;
					weight[v]=weight[u]+Time[u][v];
				}else if(dis[v]==dis[u]+length[u][v]&&weight[v]>weight[u]+Time[u][v]){
					weight[v]=weight[u]+Time[u][v];
					pre1[v]=u;
				}
			}
		}
	}
	dfs1(dest);
	dislength=dis[dest];//¼ÇÂ¼×î¶Ì¾àÀë 
	fill(dis,dis+510,inf);
	fill(visit,visit+510,0);
	pre2[src]=src;
	dis[src]=0;
	for(int i=0;i<n;i++){
		int u=-1,minn=inf;
		for(int t=0;t<n;t++){
			if(!visit[t]&&minn>dis[t]){
				minn=dis[t];
				u=t;
			}
		}
		if(u==-1)break;
		visit[u]=1;
		for(int v=0;v<n;v++){
			if(!visit[v]&&Time[u][v]!=inf){
				if(dis[v]>dis[u]+Time[u][v]){
					dis[v]=dis[u]+Time[u][v];
					pre2[v]=u;
					NodeNum[v]=NodeNum[u]+1;
				}else if(dis[v]==dis[u]+Time[u][v]&&NodeNum[v]>NodeNum[u]+1){
					pre2[v]=u;
					NodeNum[v]=NodeNum[u]+1;
				}
			} 
		}
	}
	dfs2(dest);
	distime=dis[dest];
	if(lengthpath!=timepath){
		printf("Distance = %d:",dislength);
		for(auto it=lengthpath.rbegin();it!=lengthpath.rend();it++){
			if(it!=lengthpath.rbegin())printf(" ->");
			printf(" %d",*it);
		}
	
		printf("\nTime = %d:",distime);
		for(auto it=timepath.rbegin();it!=timepath.rend();it++){
			if(it!=timepath.rbegin())printf(" ->");
			printf(" %d",*it);
		}
	}else{
		printf("Distance = %d; Time = %d:",dislength,distime);
		for(auto it=timepath.rbegin();it!=timepath.rend();it++){
			if(it!=timepath.rbegin())printf(" ->");
			printf(" %d",*it);
		}
	}
	
	return 0;
 } 
