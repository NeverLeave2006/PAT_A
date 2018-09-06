#include <iostream>
using namespace std;
int cnt,n,tree[1010],flag,a[3],post[1010];
int cmp(int a,int b){
	if(a==b)return 0;
	else return a<b?1:2;
}
void dfs(int root){
	if(root*2+1<n){
		a[cmp(tree[root],tree[2*root+1])]=1;
		dfs(2*root+1);
	}
	if(root*2+2<n){
		a[cmp(tree[root],tree[2*root+2])]=1;
		dfs(2*root+2);
	}
	post[cnt++]=tree[root];
}
int main()
{
	int m;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&tree[j]);
		}
		fill(a,a+3,0);
		cnt=0;
		dfs(0);
		if(a[1]&a[2]){
			printf("Not Heap\n");
		}else{
			if(a[1])printf("Min Heap\n");
			if(a[2])printf("Max Heap\n");
		}
		for(int i=0;i<cnt;i++){
			printf(i?" %d":"%d",post[i]);
		}
		printf("\n");
	}
	return 0;
}
