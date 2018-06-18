#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct oil{
	double price,dis;
}o[510];

bool cmp(oil o1,oil o2){
	return o1.dis<o2.dis;
}

int main()
{
	//freopen("in.txt","r",stdin);
	double Cmax,D,Davg;//油箱容量，距离，每单位油耗里程
	int N;//加油站数量 
	scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N);
	for(int i=0;i<N;i++){
		scanf("%lf%lf",&o[i].price,&o[i].dis);
	}
	sort(o,o+N,cmp);
	
	
	o[N].dis=D;
	o[N].price=0;
//	for(int i=0;i<N+1;i++){
//		printf("%.2f %.2f\n",o[i].price,o[i].dis);
//	}
//	printf("\n");
	int cnt=0;//当前第cnt站 
	double d=0,cost=0,tent=0;//已经行驶的路程 ,油的费用,油箱容量 
	if(o[0].dis!=0.0){
		printf("The maximum travel distance = 0.00");
		return 0;
	}else{
		while(cnt<N+1){
			double tmpd=d+Cmax*Davg;//从当前站点能到达的最远距离 
			if(o[cnt+1].dis>tmpd){//下一站在当前站满油能达到的距离之外 
				printf("The maximum travel distance = %.2f",tmpd);
				return 0;
			}
			double pprice=o[cnt].price,lprice=o[cnt+1].price;//当前油价，最低油价 
			int flag=0,dest=cnt+1;
			for(int i=cnt+1;i<N+1;i++){//找油价最低的下一站 
				if(o[i].dis<tmpd){
					if(pprice>o[i].price){
						dest=i;
						flag=1;
						break;
					}
					if(lprice>o[i].price){
						lprice=o[i].price;
						dest=i;
					}
				}else{
					break;//超过距离，跳出 
				}
			}
			if(flag){// 存在比当前价格低的加油站 
				cost+=((o[dest].dis-d)/Davg-tent)*o[cnt].price; //到目的地所需油量 
				d=o[dest].dis;//到目的地时的距离 
				tent=0;// 到目的地时的油量 
				cnt=dest;//目的地加油站编号 
			}else{// 不存在比当前价格低的加油站 
				cost+=(Cmax-tent)*o[cnt].price;//加满所需费用 
				tent=Cmax-(o[dest].dis-d)/Davg;
				d=o[dest].dis;
				cnt=dest;
			}
		}
		printf("%.2f",cost);	
		
	}
	return 0;
}
