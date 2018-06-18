#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[10010];
int vis[10010],isAlong[10010];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	fill(isAlong,isAlong+N+1,1);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
		isAlong[a]=0;
		isAlong[b]=0;
	}
	int K;
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		int res=1;//结果标记 
		int Nv;
		scanf("%d",&Nv);
		int arr[10010];
		fill(vis,vis+N+1,0);
		int cntM=0;
		for(int j=0;j<Nv;j++){
			scanf("%d",&arr[j]);
			//if(isAlong[arr[j]])res=0;
			if(res){
				vis[arr[j]]=1;
				for(int k=0;k<v[arr[j]].size();k++){
					if(vis[v[arr[j]][k]]==0){
						//printf("(%d,%d)",arr[j],v[arr[j]][k]);
						cntM++;
					}
				}
			}
		}
		if(cntM<M)res=0;
		printf(res?"Yes\n":"No\n");
	}
	return 0;
}
