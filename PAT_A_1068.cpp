#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int coins[10010];
int dp[10010];
int choice[10010][10010];
int flag[10010]={0};

bool cmp(int a,int b){
	return a>b;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++){
		scanf("%d",&coins[i]);
	}
	sort(coins+1,coins+1+N,cmp);
	for(int i=1;i<=N;i++){
		for(int v=M;v>=coins[i];v--){
			if(dp[v]<=dp[v-coins[i]]+coins[i]){
				dp[v]=dp[v-coins[i]]+coins[i];
				choice[i][v]=1;
			}else{
				choice[i][v]=0;
			}
		}
	}
	if(dp[M]!=M)printf("No Solution");
	else{
		int k=N,num=0,v=M;
		while(k>=0){
			if(choice[k][v]==1){
				flag[k]=1;
				v-=coins[k];
				num++;
			}else{
				flag[k]=0;
			}
			k--;
		}
		for(int i=N;i>=1;i--){
			if(flag[i]){
				printf("%d",coins[i]);
				num--;
				printf(num?" ":"");
			}
		}
	}
	return 0;
}
