#include <iostream>
#include <map>
using namespace std;
int main()
{
	int M,N;
	scanf("%d%d",&M,&N);
	map<int,int> iMi;
	int max=0,values;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int tmp;
			scanf("%d",&tmp);
			iMi[tmp]++;//int是基本类型，默认值为0 
			if(iMi[tmp]>max){
				max=iMi[tmp];
				values=tmp;
			}
		}
	}
	printf("%d",values);
	return 0;
}
