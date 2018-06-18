#include <iostream>
#include <queue>
using namespace std;

struct mouse{
	int weight;
	int order;
}m[1010];
int arrays[1010];

int main()
{
	int Np,Ng;
	scanf("%d%d",&Np,&Ng);
	
	for(int i=0;i<Np;i++){
		mouse tmp;
		scanf("%d",&tmp.weight);
		tmp.order=0;
		m[i]=tmp;
	}
	queue<int> q;
	for(int i=0;i<Np;i++){
		int rank; 
		scanf("%d",&rank);
		q.push(rank);
	}
	
	int tmpNp=Np;
	while(q.size()!=1){
		int group=tmpNp/Ng;
		if(tmpNp%Ng)group+=1;
		for(int i=0;i<group;i++){
			int max=q.front();
			for(int j=0;j<Ng;j++){
				if(i*Ng+j>=tmpNp)break;
				if(m[max].weight<m[q.front()].weight){
					max=q.front();
				}
				m[q.front()].order=group+1;
				q.pop();
			}
			q.push(max);
		}
		tmpNp=group;
	}
	m[q.front()].order=1;
	for(int i=0;i<Np;i++){
		if(i)printf(" ");
		printf("%d",m[i].order);
	}
	return 0;
}
