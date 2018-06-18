#include <iostream>

using namespace std;

int arr[10010],N,exist[10010],cnt[10010];

int findFather(int a){
	int acpy=a;
	while(arr[a]!=a){
		a=arr[a];
	}
	arr[acpy]=a;//»¯¼ò 
	return a;
}

void Union(int a,int b){
	int fa=findFather(a);
	int fb=findFather(b);
	if(fa!=fb)arr[fa]=fb;
}

int main()
{
	scanf("%d",&N);
	for(int i=1;i<10010;i++){
		arr[i]=i;
	}
	for(int i=0;i<N;i++){
		int K,root;
		scanf("%d%d",&K,&root);
		exist[root]=1;
		for(int j=0;j<K-1;j++){
			int tmp;
			scanf("%d",&tmp);
			Union(root,tmp);
			exist[tmp]=1;
		} 
	}
	for(int i=0;i<10010;i++){
		if(exist[i]){
			int root=findFather(i);
			cnt[root]++;
		}
	}
	int sum=0,cntT=0;
	for(int i=0;i<10010;i++){
		if(cnt[i]){
			sum+=cnt[i];
			cntT++;
		}
	}
	printf("%d %d\n",cntT,sum);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		printf(findFather(a)==findFather(b)?"Yes\n":"No\n");
	}
	return 0;
}
