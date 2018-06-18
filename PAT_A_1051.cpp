#include <iostream>
#include <stack> 
using namespace std;

int seq[1010];

int main()
{
	int M,N,K;
	scanf("%d%d%d",&M,&N,&K);
	stack<int> ss;
	while(K--){
		int flag=1; 
		while(!ss.empty()){
			ss.pop();
		}
		for(int i=0;i<N;i++){
			scanf("%d",&seq[i]);
		}
		int cur=0;
		for(int i=1;i<=N;i++){
			if(ss.empty()||ss.top()!=seq[cur]){
				ss.push(i);
			}
			if(ss.size()>M){
				flag=0;
				break;
			}
			while(!ss.empty()&&ss.top()==seq[cur]){//¶ÌÂ·Óë 
				ss.pop();
				cur++;
			}
		}
		if(ss.empty()&&flag){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}
