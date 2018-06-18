#include <iostream>
#include <map>
using namespace std;

bool isPrime(int N){
	if(N==2)return true;
	for(int i=2;i*i<=N;i++){
		if(N%i==0)return false;
	}
	return true;
}

int main()
{
	int N;
	scanf("%d",&N);
	map<int,int> m_ii;
	if(N==1)printf("%d=1\n",N);
	int Ncpy=N;
	for(int i=2;i*i<=N;i++){
		if(N==0)break;
		if(!isPrime(i))continue;
		if(N%i==0)m_ii[i]=0;
		while(N%i==0){
			m_ii[i]++;
			N/=i;
		}
	}
	if(N!=1){
		m_ii[N]=1;
	}
	map<int,int>::iterator it=m_ii.begin();
	if(Ncpy!=1)printf("%d",Ncpy);
	while(it!=m_ii.end()){
		if(it==m_ii.begin())printf("=");
		else printf("*");
		printf("%d",it->first);
		if(it->second>1)printf("^%d",it->second);
		it++;
	}
	return 0;
}
