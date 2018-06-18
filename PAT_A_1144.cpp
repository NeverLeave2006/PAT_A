#include <iostream>

using namespace std;
int arr[100010];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		if(tmp<0||tmp>100001)continue;
		arr[tmp]=1;
	}
	for(int i=1;i<100010;i++){
		if(!arr[i]){
			printf("%d",i);
			break;
		}
	}
	return 0;
}
