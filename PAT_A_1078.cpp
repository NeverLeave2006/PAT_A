#include <iostream>

using namespace std;

int a[10000]={0};

bool isPrime(int N){
	if(N==1)return false;
	if(N==2)return true;
	for(int i=2;i*i<=N;i++){
		if(N%i==0)return false;
	} 
	return true;
}

int main()
{
	
	int Msize,N;
	scanf("%d %d",&Msize,&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	int Tsize=Msize;
	while(!isPrime(Tsize)){
		Tsize++;
	}
	int f[Tsize]={0};
	for(int cnt=0;cnt<N;cnt++){
		int flag=1;
		for(int i=0;i<Tsize;i++){
			if(!f[(a[cnt]+i*i)%Tsize]){
				if(cnt!=0)printf(" ");
				printf("%d",(a[cnt]+i*i)%Tsize);
				f[(a[cnt]+i*i)%Tsize]=1;
				flag=0;
				break;
			}
		}
		if(cnt!=0&&flag)printf(" ");
		if(flag)printf("-");
	}
	
	
	return 0;
}
