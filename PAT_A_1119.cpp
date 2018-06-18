#include <iostream>
using namespace std;
int N;
int a[40],b[40],c[40],cur=0,ok=1;
void check(int l1,int r1,int l2,int r2){
	if(l1>r1)ok=0;
	if(l1==r1){
		c[cur++]=a[l1];
		return;
	}
	int i=l1+1;
	for(;i<=r1;i++){
		if(a[i]==b[r2-1])break;
	}
	if(i-l1>1){
		check(l1+1,i-1,l2,l2+(i-l1-1)-1);
	}else{
		ok=0;
	}
	c[cur++]=b[r2];
	check(i,r1,l2+(i-l1-1),r2-1);
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&b[i]);
	}
	check(0,N-1,0,N-1);
	printf(ok?"Yes\n":"No\n");
	for(int i=0;i<N;i++){
		printf("%d%c",c[i],i==N-1?'\n':' ');
	}
	return 0;
}
