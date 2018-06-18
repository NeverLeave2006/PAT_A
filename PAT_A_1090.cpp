#include <iostream>
#include <vector>
using namespace std;

int N;
double P,r;
double hP=0;
int hI;

vector<int> Node[100010];

void DFS(int root,double p){
	if(Node[root].empty()){
		if(p>hP){
			hP=p;
			hI=1;
		}else if(p==hP){
			hI++;
		}
	}else{
		p*=(1+r/100);
		for(int i=0;i<Node[root].size();i++){
			int idx=Node[root][i];
			DFS(idx,p);
		}
	}
}

int main()
{
	scanf("%d",&N);
	scanf("%lf%lf",&P,&r);
	int root;
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		if(tmp==-1){
			root=i;
		}else{
			Node[tmp].push_back(i);
		}
	}
	DFS(root,P);
	printf("%.2lf %d",hP,hI);
	return 0;
}
