#include <cstdio>
#include <set>
#include <cmath>
using namespace std;

set<int> si;
struct Node{
	int Data;
	int Next;
}n[100010];
int a[100010],b[100010];

int main()
{
	int head,N;
	scanf("%d%d",&head,&N);
	for(int i=0;i<N;i++){
		int pos,data,next;
		scanf("%d%d%d",&pos,&data,&next);
		n[pos].Data=data;
		n[pos].Next=next; 
	}
	int cnta=0,cntb=0;
	while(head!=-1){
		Node tmp=n[head];
		if(si.count(abs(tmp.Data))){
			a[cnta++]=head;
		}else{
			b[cntb++]=head;
			si.insert(abs(tmp.Data));
		}
		head=tmp.Next;
	}
	printf("%05d %d",b[0],n[b[0]].Data);
	for(int i=1;i<cntb;i++){
		printf(" %05d\n%05d %d",b[i],b[i],n[b[i]].Data);
	}
	printf(" -1\n");
	if(cnta!=0){
		printf("%05d %d",a[0],n[a[0]].Data);
		for(int i=1;i<cnta;i++){
			printf(" %05d\n%05d %d",a[i],a[i],n[a[i]].Data);
		}
		printf(" -1\n");
	}
	
	return 0;
}
