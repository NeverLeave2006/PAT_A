#include <iostream>
#include <algorithm>
using namespace std;

int tre[1010],n[1010];
int N,cnt=0;

void inOrder(int root){
	if(2*root<=N){
		inOrder(2*root);
	}
	tre[root]=n[cnt++];
	if((2*root+1)<=N){
		inOrder(2*root+1);
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&n[i]);
	}
	sort(n,n+N);
	inOrder(1);
	for(int i=1;i<=N;i++){
		printf(i!=1?" ":"");
		printf("%d",tre[i]);
	} 
	return 0;
}
