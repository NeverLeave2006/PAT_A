#include <iostream>
#include <queue> 
#include <algorithm> 
using namespace std;

int People[1010],endTime[1010];//排队者,结束时间
queue<int> Que[20]; 

int main()
{
	int N,M,K,Q;//窗口数，队列容量,排队者人数，要求解的人 
	scanf("%d%d%d%d",&N,&M,&K,&Q);
	for(int i=1;i<=K;i++){
		scanf("%d",&People[i]);
	}
	int order=1;
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			Que[j].push(order);
			order++;
			if(order>K){
				order=-1;
			}
		}
		if(order==-1)break;
	}
	int flag=1;//结束标记 
	fill(endTime,endTime+K+1,1000);
	for(int i=1;i<=540;i++){
		for(int j=0;j<N;j++){
			if(!Que[j].empty()){
				int first=Que[j].front();
				People[first]--;
				if(People[first]==0){
					endTime[first]=i;
					Que[j].pop();
					if(flag){
						Que[j].push(order);
						order++;
					}
					if(order>K){
						flag=0;
					}
				}
			}
			
		}
	}
	for(int i=0;i<N;i++){
		if(!Que[i].empty()){
			
		}
	}
	for(int i=0;i<Q;i++){
		int q;
		scanf("%d",&q);
		int t=endTime[q];
		if(t<=540){
			int h,m;
			m=t%60;
			h=t/60;
			printf("%02d:%02d\n",h+8,m);
		}else{
			printf("Sorry");
		}
		
	}
	return 0;
}
