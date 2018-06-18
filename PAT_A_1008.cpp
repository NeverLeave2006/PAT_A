#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	int tmp=0,s=N*5;
	for(int i=0;i<N;i++){
		int level;
		scanf("%d",&level);
		if(level>tmp){
			s+=(level-tmp)*6;
		}if(level<tmp){
			s+=(tmp-level)*4;
		}
		tmp=level;
	}
	printf("%d",s);
	return 0;
}
