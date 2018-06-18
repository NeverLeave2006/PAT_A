#include <iostream>
#include <algorithm>
using namespace std;
int a[1000010],b[1000010];
int inf=2147483647;
int main()
{
	int N1,N2;
	scanf("%d",&N1);
	for(int i=0;i<N1;i++){
		scanf("%d",&a[i]);
	}
	a[N1]=inf;
	scanf("%d",&N2);
	for(int i=0;i<N2;i++){
		scanf("%d",&b[i]);
	}
	b[N2]=inf;
	int mid=(N1+N2-1)/2;
	int i=0,j=0,cnt=0;
	while(cnt<mid){
		if(a[i]<b[j]){
			i++;
		}else{
			j++;
		}
		cnt++;
	}
	if(a[i]<b[j]){
		printf("%d",a[i]);
	}else{
		printf("%d",b[j]);
	}
	return 0;
} 
