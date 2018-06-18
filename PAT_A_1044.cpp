#include <iostream>
#include <iostream>
using namespace std;


int a[100010]={0};
int mm=100000000;

int find(int i,int j,int M){
	int mid;
	while(i<j){
		mid=(i+j)/2;
		if(a[mid]>M){
			j=mid;
		}else{
			i=mid+1;
		}
		
	}
	return i;
}


int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	int sum=0;
	for(int i=1;i<=N;i++){
		int tmp;
		scanf("%d",&tmp);
		sum+=tmp;
		a[i]=sum;
	}
	for(int i=1;i<=N;i++){
		int x=find(i,N+1,M+a[i-1]);
		if(a[x-1]-a[i-1]==M){
			mm=M;
			break;
		}
		if(x<=N&&a[x]-a[i-1]<mm){
			mm=a[x]-a[i-1];
		}
	}
	
	for(int i=1;i<=N;i++){
		int x=find(i,N+1,mm+a[i-1]);
		if(a[x-1]-a[i-1]==mm){
			printf("%d-%d\n",i,x-1);
		}
	}
	return 0;
}
