#include <iostream>
#include <cmath>
using namespace std;

int a[1001],N;

bool check(){
	for(int k=0;k<N-1;k++){
			for(int l=k+1;l<N;l++){
				if(abs(a[k]-a[l])==abs(k-l)||(a[k]-a[l])==0){
					return false;
				}
			}
		}
	return true;
}

int main()
{
	int K;
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		scanf("%d",&N);
		for(int j=0;j<N;j++){
			scanf("%d",&a[j]);
		}
		if(check()){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
