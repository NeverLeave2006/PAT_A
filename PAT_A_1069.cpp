#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int N){
	int d[4];
	do{
		for(int i=0;i<4;i++){
			d[i]=N%10;
			N/=10;
		}
		sort(d,d+4);
		int a=0,b=0;
		for(int i=0;i<4;i++){
			a*=10;
			b*=10;
			a+=d[3-i];
			b+=d[i];
		}
		N=a-b;
		printf("%04d - %04d = %04d\n",a,b,N);
	}while(N&&N!=6174);
}


int main()
{
	int N;
	scanf("%d",&N);
	solve(N);
	return 0;
}
