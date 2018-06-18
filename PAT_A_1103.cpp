#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int arr[22];

int N,K,P;
int Sum=-1;
vector<int> ansv,tmpv;

int power(int a){
	int res=1;
	for(int i=0;i<P;i++){
		res*=a;
	}
	return res;
}

void DFS(int index,int sum,int fac,int maxSum){//当前选第几个数，所选数的和 
	if(sum>N||index>K){
		return;
	}
	if(index==K&&sum==N){
		if(maxSum>Sum){
			Sum=maxSum;
			ansv=tmpv;
		}
		return;
	}
	if(fac-1>=0){
		tmpv.push_back(fac);
		DFS(index+1,sum+arr[fac],fac,maxSum+fac);
		tmpv.pop_back();
		DFS(index,sum,fac-1,maxSum);
	}
	
} 

int main()
{
	scanf("%d%d%d",&N,&K,&P);
	int cnt;
	for(cnt=0;power(cnt)<=N;cnt++){//初始化 
		if(power(cnt)<=N){
			arr[cnt]=power(cnt);
		}else{
			break;
		}
	}
	DFS(0,0,cnt-1,0);
	if(Sum!=-1){
		printf("%d = ",N);
		for(int i=0;i<ansv.size();i++){
			if(i)printf(" + ");
			printf("%d^%d",ansv[i],P);
		}
	}else{
		printf("Impossible");
	}
	
	
	return 0;
}
