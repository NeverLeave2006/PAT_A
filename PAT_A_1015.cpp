#include <iostream>
#include <queue>
using namespace std;

bool isPrime(int x){
	if(x<=1)return false;
	if(x==2)return true;
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return false;
	}
	return true;
} 

int main()
{
	int N,D;
	while(cin>>N){
		int n=N;
		queue<int> iqueue;
		if(n<0)break;
		cin>>D;
		while(n!=0){
			iqueue.push(n%D);
			n/=D;
		}
		int tmp=0;
		while(!iqueue.empty()){
			tmp*=D;
			tmp+=iqueue.front();
			iqueue.pop();
		}
		if(isPrime(tmp)&&isPrime(N))cout<<"Yes"<<endl;
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
