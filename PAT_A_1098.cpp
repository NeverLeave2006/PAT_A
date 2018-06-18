#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[110],arr2[110];

bool isQS(int &k){
	int i;
	for(i=2;i<=N;i++){
		if(arr2[i]-arr2[i-1]<0)
			break;
	}
	k=i;
	for(;i<=N;i++){
		if(arr[i]!=arr2[i]){
			return false;
		}
	}
	return true;
}

bool isMax(int k){
	for(int i=1;i<k;i++){
		if(arr2[i]>arr2[k]){
			return false;
		}
	}
	return true;
}

void Modify(int k){
	swap(arr2[1],arr2[k]);
	int i=1,j=2*i;
	while(j<k){
		int flag=0;
		if(arr2[j]<arr2[j+1]&&j+1<k)j++;
		if(arr2[j]>arr2[i]){
			swap(arr2[i],arr2[j]);
			i=j;
			j=i*2;
			flag=1;
		}
		if(!flag)break;
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<=N;i++){
		scanf("%d",&arr2[i]);
	}
	int k=0;
	if(isQS(k)){
		sort(arr2+1,arr2+k+1);
		printf("Insertion Sort\n");
		for(int i=1;i<=N;i++){
			printf(i!=1?" ":"");
			printf("%d",arr2[i]);
		}
	}else{
		printf("Heap Sort\n");
		int m;
		for(m=N;m>=0;m--){
			if(!isMax(m)){
				break;
			}
		}
		Modify(m);
		for(int i=1;i<=N;i++){
			printf(i!=1?" ":"");
			printf("%d",arr2[i]);
		}
	}
	return 0;
}
