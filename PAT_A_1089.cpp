#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[110],b[110];
bool cmp(){
	for(int i=0;i<N;i++){
		if(a[i]!=b[i]){
			return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&b[i]);
	}
	int cnt=0;
	for(int i=1;i<N;i++){
		cnt++;
		if(b[cnt]<b[cnt-1]){
			break;
		}
	}
	int flag=0;
	for(int i=cnt;i<N;i++){
		if(a[i]!=b[i]){
			flag=1;
			break;
		}
	}
	if(flag){
		printf("Merge Sort\n");
		int w=0;
		for(int i=2;i<N;i*=2){
			for(int j=0;j<N/i;j++){
				sort(a+j*i,a+i*(j+1));
			}
			sort(a+i*(N/i),a+N);
			if(cmp()){
				w=i*2;
				break;
			}
		} 
		for(int j=0;j<N/w;j++){
			sort(a+j*w,a+w*(j+1));
		}
		sort(a+w*(N/w),a+N);
	}else{
		printf("Insertion Sort\n");
		sort(a,a+cnt+1);
	}
	for(int i=0;i<N;i++){
		printf(i?" ":"");
		printf("%d",a[i]);
	}
	return 0;
}
