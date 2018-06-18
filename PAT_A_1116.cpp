#include <iostream>
#include <map>
#include <set>
using namespace std;


set<string> ss;

bool isPrime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return false;
	}
	return true;
}

int main()
{
	map<string,int> m_si;
	int N;
	scanf("%d",&N);
	getchar();
	for(int i=0;i<N;i++){
		string tmp;
		
		getline(cin,tmp);
		ss.insert(tmp);
		m_si[tmp]=i;
	}
	scanf("%d",&N);
	getchar();
	for(int i=0;i<N;i++){
		string s;
		getline(cin,s);
		if(!ss.count(s)){
			cout<<s;
			printf(": Are you kidding?\n");
			continue;
		}
		int rank=m_si[s];
		if(rank==0){
			cout<<s;
			printf(": Mystery Award\n");
			m_si[s]=-1;
			continue;
		}else if(isPrime(rank+1)&&rank!=-1){
			cout<<s;
			printf(": Minion\n");
			m_si[s]=-1;
			continue;
		}else if(rank==-1){
			cout<<s;
			printf(": Checked\n");
			m_si[s]=-1;
			continue;
		}else{
			cout<<s;
			printf(": Chocolate\n");
			m_si[s]=-1;
			continue;
		}
	}
	return 0;
}
