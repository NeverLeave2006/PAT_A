#include <iostream>
#include <algorithm>
using namespace std;

int pos[100010];//Œª÷√ 

int main()
{
	int N;
	int cnt=0;
	int k=1; 
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		pos[tmp]=i;
	}
	while(k<N){
		while(pos[0]!=0){
			swap(pos[0],pos[pos[0]]);
			cnt++;
		}
		if(pos[0]==0){
			for(;k<N;k++){
				if(pos[k]!=k){
					swap(pos[0],pos[k]);
					cnt++;
					break;
				}
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
