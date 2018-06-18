#include <iostream>
using namespace std;

int c[1002]={0};

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		c[tmp]++;
	}
	int flag=1;
	for(int i=0;i<500;i++){
		if(c[i]){
			c[i]--;
			if(c[M-i]){
				printf("%d %d\n",i,M-i);
				flag=0;
				break;
			}
			c[i]++;
		}
	}
	if(flag)printf("No Solution\n"); 
	return 0;
}
