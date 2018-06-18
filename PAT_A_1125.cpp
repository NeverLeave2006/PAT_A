#include <iostream>
#include <algorithm> 
using namespace std;

int ropes[10010];
int cnt=0;

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		cin>>ropes[i];
	}
	sort(ropes,ropes+N);
	int r=ropes[0]+ropes[1];
	r/=2;
	for(cnt=2;cnt<N;cnt++){
		r=(r+ropes[cnt])/2;
	}
	printf("%d",r);
 } 
