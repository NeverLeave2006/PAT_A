#include <iostream>
#include <algorithm>
using namespace std;

int a[12];

int num(int* a,int n){
	int res=0;
	reverse(a,a+n);
	for(int i=0;i<n;i++){
		res*=10;
		res+=a[i];
	}
	return res;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int tmp,tmp1;
		scanf("%d",&tmp1);
		tmp=tmp1;
		int cnt=0;
		while(tmp!=0){
			a[cnt++]=tmp%10;
			tmp/=10;
		}
		int s=num(a,cnt/2);
		int n=num(a+cnt/2,cnt/2);
		if(s*n==0){
			printf("No\n");
			continue;
		}
		if(tmp1%(s*n)==0){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
