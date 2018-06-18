#include <iostream>
#include <algorithm>
using namespace std;

int a[100010];

int main()
{
	int N,p;
	scanf("%d%d",&N,&p);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+N);
	int ans=1;
	for(int i=0;i<N;i++){
		int pos=upper_bound(a+i+1,a+N,(long long)a[i]*p)-a;//二分查找上界！！！ 
		ans=max(ans,pos-i);
	}
	printf("%d",ans);
	return 0;
}
