#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int data;
	int next;
}n[100010];

int arr[100010];

int main()
{
	int head,N,K;
	scanf("%d%d%d",&head,&N,&K);
	for(int i=0;i<N;i++){
		int pos,d,next;
		scanf("%d%d%d",&pos,&d,&next);
		n[pos].data=d;
		n[pos].next=next;
	}
	int cnt=0;
	while(head!=-1){
		arr[cnt++]=head;
		head=n[arr[cnt-1]].next;
	}
	for(int i=0;i<=cnt-K;i+=K){
		reverse(arr+i,arr+i+K);
	}
	printf("%05d %d",arr[0],n[arr[0]].data);
	for(int i=1;i<cnt;i++){
		printf(" %05d\n%05d %d",arr[i],arr[i],n[arr[i]].data);
	}
	printf(" -1");
	return 0;	
} 
