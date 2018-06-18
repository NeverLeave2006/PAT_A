#include <iostream>
#include <map>
using namespace std;

bool IsPrime(int a){
	if(a==2||a==3)return true;
	for(int i=2;i<a;i++){
		if(a%i==0)return false;
	}
	return true;
}
int occupy[10002];
map<int,int> mii;
int main()
{
	int Msize,N,M;
 	scanf("%d%d%d",&Msize,&N,&M);
 	while(IsPrime(Msize))Msize++;
 	for(int i=0;i<N;i++){
 		int time=1;
 		int tmp;
 		scanf("%d",&tmp);
 		if(occypu[(tmp+time*time)%Msize]){
 			time++;
		}else if(time){
			mii[tmp]=time;
		}
	}
	
	return 0;
} 
