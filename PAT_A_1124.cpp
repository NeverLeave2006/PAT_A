#include <iostream>
#include <set>
using namespace std;

string a[10001];
set<string> s_s;

int main()
{
	int M,N,S;
	scanf("%d%d%d",&M,&N,&S);
	getchar();
	int cnt=0;
	for(int i=0;i<M;i++){
		string tmp;
		getline(cin,tmp);
		a[cnt++]=tmp;
	}
	int flag=1;
	cnt=N;
	for(int i=S-1;i<M;i++){
		if(cnt==N){
			if(!s_s.count(a[i])){
				cout<<a[i]<<endl;
				s_s.insert(a[i]);
				flag=0;
				cnt=0;
			}else{
				cnt--;
			}
			
		}
		cnt++;
	}
	if(flag){
		printf("Keep going...\n");
	}
	return 0;
}
