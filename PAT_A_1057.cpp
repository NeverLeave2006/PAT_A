#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int N;

int block[317];
int table[100010];
stack<int> si;

void Pop(){
	int x=si.top();
	si.pop();
	printf("%d\n",x);
	block[x/317]--;
	table[x]--;
}

void Push(int x){
	si.push(x);
	block[x/317]++;
	table[x]++;
}

void PeekMedian(){
	int sum=0,m;
	if(si.size()%2){
		m=(si.size()+1)/2;
	}else{
		m=si.size()/2;
	}
	int k;
	for(k=0;k<317;k++){
		if(sum+block[k]>=m){
			break;
		}
		sum+=block[k];
	}
	k*=317;
	for(int i=0;i<317;i++){
		if(sum+table[k+i]>=m){
			printf("%d\n",k+i);
			break;
		}
		sum+=table[k+i];
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		char cmd[10];
		scanf("%s",cmd);
		if(strcmp(cmd,"Pop")==0){
			if(si.size()==0){
				printf("Invalid\n");
			}else{
				Pop();
			}
		}
		if(strcmp(cmd,"PeekMedian")==0){
			if(si.size()==0){
				printf("Invalid\n");
			}else{
				PeekMedian();
			}
		}
		if(strcmp(cmd,"Push")==0){
			int tmp;
			scanf("%d",&tmp);
			Push(tmp);
		}
	}
	return 0;
}
