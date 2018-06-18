#include <iostream>
#include <algorithm>
using namespace std;

int N;
int hobby[1010]={0},father[1010]={0},isRoot[11010]={0};

bool cmp(int a,int b){
	return a>b;
}

int findFather(int x){
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	while(a!=father[a]){//Â·¾¶Ñ¹Ëõ 
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}

int Union(int a,int b){
	int fa=findFather(a);
	int fb=findFather(b);
	if(fa!=fb)father[fa]=fb;
}

int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		father[i]=i;
	}
	for(int i=1;i<=N;i++){
		int k;
		scanf("%d:",&k);
		for(int j=0;j<k;j++){
			int tmp;
			scanf("%d",&tmp);
			if(hobby[tmp]==0){
				hobby[tmp]=i;
			}
			Union(i,findFather(hobby[tmp]));
		} 
	}
	for(int i=1;i<=N;i++){
		isRoot[findFather(i)]++;
	}
	int cnt=0;
	for(int i=1;i<=N;i++){
		if(isRoot[i])cnt++;
	}
	printf("%d\n",cnt);
	sort(isRoot+1,isRoot+N+1,cmp);
	for(int i=1;i<=cnt;i++){
		printf(i!=1?" ":"");
		printf("%d",isRoot[i]);
	} 
	return 0;
}
