#include <iostream>
#include <vector>
using namespace std;

struct Node{
	double price;
	vector<int> child;
}nn[100010];

int N;
double P,r;
double lprice=2E10;
int l=0;

void DFS(int root,double price){
	nn[root].price=price;
	price*=(1+r/100);
	if(nn[root].child.size()){
		for(int i=0;i<nn[root].child.size();i++){
			int idx=nn[root].child[i];
			DFS(idx,price);
		}
	}else{
		if(nn[root].price<lprice){
			lprice=nn[root].price;
			l=1;
		}else if(nn[root].price==lprice){
			l++;
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
			nn[i].child.push_back(tmp);
		}
	}
	DFS(0,P);
	printf("%.4lf %d",lprice,l);
	return 0;
}
