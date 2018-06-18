#include <iostream>
#include <algorithm>
#include <string>
#define inf 1000000000
#define maxv 1020
using namespace std;

int N,M,K,Ds,vis[maxv];
int dis[maxv][maxv];
int d[maxv];

int index(string s){
	if(s[0]=='G'){
		s=s.substr(1);
		return stoi(s)+N;
	}else{
		return stoi(s);
	}
}

void Dijkstra(){
	for(int j=0;j<M+N;j++){
		int u=-1,length=inf;
		for(int i=1;i<=M+N;i++){
			if(length>d[i]&&!vis[i]){
				u=i;
				length=d[i];
			}
		}
		if(u==-1)return;
		vis[u]=1;
		for(int i=1;i<=M+N;i++){
			if(dis[u][i]+d[u]<d[i]&&!vis[i]){
				d[i]=dis[u][i]+d[u];
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d",&N,&M,&K,&Ds);
	fill(dis[0],dis[0]+maxv*maxv,inf);
	for(int i=0;i<K;i++){
		string a,b;
		int length;
		cin>>a>>b>>length;
		dis[index(a)][index(b)]=length;
		dis[index(b)][index(a)]=length;
	}
	int pos=-1;
	double ansdis=-1,ansavg=inf;
	for(int i=1;i<=M;i++){
		fill(d,d+maxv,inf);
		d[N+i]=0;
		fill(vis,vis+maxv,0);
		Dijkstra();
		double avg=0,mindis=inf;
		for(int k=1;k<=N;k++){
			if(d[k]>Ds){
				mindis=-1;
				pos=-2;
				break;
			}else{
				if(mindis>d[k]){
					mindis=d[k];
				}
				avg+=1.0*d[k];
			}
		}
		if(mindis==-1)continue;
		avg/=N;
		if(mindis>ansdis){
			pos=i;
			ansdis=mindis;
			ansavg=avg;
		}else if(mindis==ansdis&&ansavg>avg){
			pos=i;
			ansavg=avg;
		}
	}
	if(pos<0){
		printf("No Solution");
	}else{
		printf("G%d\n%.1f %.1f",pos,ansdis,ansavg);
	}
	
	return 0;
}
