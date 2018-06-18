#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int a[100010];

int main()
{
	int N;
	scanf("%d",&N);
	printf("%d ",N%2);
	int sum=0;
	//priority_queue<int> Q;
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a,a+N);
	int subsum=0;
	for(int i=0;i<(N/2);i++){
		subsum+=a[i];
	}
	int s1=abs(sum-2*subsum),s2=0;
	if(N%2){
		subsum+=a[N/2+1];
		int s2=abs(sum-2*subsum);
	}
	
	printf("%d",s1>s2?s1:s2);
}
