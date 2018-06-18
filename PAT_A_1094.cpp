#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
	int generation;
	vector<int> childs;
}nn[110];

int N,M;
int num[110]={0};
int maxNum=0,maxLv;

int LayerOrder(int root,int generation){
	queue<int> Q;
	Q.push(root);
	nn[root].generation=generation;
	num[generation]++;
	while(!Q.empty()){
		int t=Q.front();
		Q.pop();
		if(!nn[t].childs.empty()){
			for(int i=0;i<nn[t].childs.size();i++){
				int idx=nn[t].childs[i];
				nn[idx].generation=nn[t].generation+1;
				Q.push(idx);
				int ger=nn[idx].generation;
				num[ger]++; 
			}
		}
	} 
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int id,num;
		scanf("%d%d",&id,&num);
		for(int j=0;j<num;j++){
			int tmp;
			scanf("%d",&tmp);
			nn[id].childs.push_back(tmp);
		}
	}
	LayerOrder(01,1);
	for(int i=1;i<=N;i++){
		if(num[i]>maxNum){
			maxNum=num[i];
			maxLv=i;
		}
	}
	printf("%d %d",maxNum,maxLv);
	return 0;
}
