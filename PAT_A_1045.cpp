#include <iostream>
#include <algorithm>
#define inf 1000000000
using namespace std;

int N,M,L;
int mm[210],ll[10010],dp[10010];
int ans=0;

int main()
{
	scanf("%d%d",&N,&M);
	fill(mm,mm+210,inf);
	for(int i=1;i<=M;i++){
		int tmp;
		scanf("%d",&tmp);
		mm[tmp]=i;
	}
	scanf("%d",&L);
	int cnt=0;
	for(int i=0;i<L;i++){
		int tmp;
		scanf("%d",&tmp);
		if(mm[tmp]<inf){
			ll[cnt++]=mm[tmp];
		}
	}
	int ans=-1;
	for(int i=0;i<cnt;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(ll[j]<=ll[i]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
		if(dp[i]>ans){
			ans=dp[i];
		}
	}
	printf("%d",ans);
	return 0;
}
