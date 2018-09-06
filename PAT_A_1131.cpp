#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
map<int,map<int,int> > graph;//地铁地图 
int src,dest,inf=99999999;
int visit[10010],minnumofnode=inf,nodenum=0,minnumofline=inf,curline=-1,cur;
vector<int> line,respath;
int Transfer(vector<int> path){
	int pre=path[0],cnt=1;
	int preline=graph[pre][path[1]];
	pre=path[1];
	for(int i=2;i<path.size();i++){
		if(preline!=graph[pre][path[i]]){
			cnt++;
			preline=graph[pre][path[i]];
		}
		pre=path[i];
	}
	return cnt;
}
void dfs(int v){
	if(v!=dest){
		map<int,int> t=graph[v];
		for(auto it=t.begin();it!=t.end();it++){
			if(!visit[it->first]){
				nodenum++;
				line.push_back(it->first);
				visit[it->first]=1;
				dfs(it->first);
				visit[it->first]=0;
				line.pop_back();
				nodenum--;
			}
		}
	}else{
		if(nodenum<minnumofnode){
			minnumofline=Transfer(line);
			minnumofnode=nodenum;
			respath=line;
		}else if(minnumofnode==nodenum&&minnumofline>Transfer(line)){
			minnumofline=Transfer(line);
			respath=line;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int k,pre;
		scanf("%d%d",&k,&pre);
		for(int j=0;j<k-1;j++){
			int tmp;
			scanf("%d",&tmp);
			graph[pre][tmp]=i;//任意两个节点之间所属的的线路 
			graph[tmp][pre]=i;
			pre=tmp;
		}
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d%d",&src,&dest);
		fill(visit,visit+10010,0);
		minnumofnode=inf;
		minnumofline=inf;
		line.clear();
		line.push_back(src);
		visit[src]=1;
		curline=-1;
		cur=src;
		dfs(src);
		printf("%d\n",minnumofnode);
		curline=graph[src][respath[1]];
		cur=respath[1];
		for(int i=2;i<respath.size();i++){
			if(curline!=graph[cur][respath[i]]){
				printf("Take Line#%d from %04d to %04d.\n",curline,src,cur);
				src=cur;
				curline=graph[cur][respath[i]];
			}
			cur=respath[i];
		}
		printf("Take Line#%d from %04d to %04d.\n",curline,src,cur);
	}
	return 0;
}
