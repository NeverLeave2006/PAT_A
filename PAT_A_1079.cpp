#include <iostream>
#include <vector>
using namespace std;

struct Node{
	double price;
	int amount;
	vector<int> next;
}nn[100010];

int N;//节点数 
double P,r,sum;//原价，利润率 

void preOrder(int root,double p){
	nn[root].price=p;
	p*=(r/100+1);
	if(nn[root].next.empty()){
		sum+=nn[root].price*nn[root].amount;
	}else{
		for(int i=0;i<nn[root].next.size();i++){
			int nex=nn[root].next[i];
			preOrder(nex,p);
		}
	}
}

int main()
{
	scanf("%d",&N);
	scanf("%lf%lf",&P,&r);
	for(int i=0;i<N;i++){
		int num;
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			int tmp;
			scanf("%d",&tmp);
			nn[i].next.push_back(tmp);
		}
		if(!num){
			int tmp;
			scanf("%d",&tmp);
			nn[i].amount=tmp;
		}
	}
	preOrder(0,P);
	printf("%.1f",sum);
	return 0;
}
