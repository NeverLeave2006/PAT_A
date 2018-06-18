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
	double Cmax,D,Davg;//�������������룬ÿ��λ�ͺ����
	int N;//����վ���� 
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
	int cnt=0;//��ǰ��cntվ 
	double d=0,cost=0,tent=0;//�Ѿ���ʻ��·�� ,�͵ķ���,�������� 
	if(o[0].dis!=0.0){
		printf("The maximum travel distance = 0.00");
		return 0;
	}else{
		while(cnt<N+1){
			double tmpd=d+Cmax*Davg;//�ӵ�ǰվ���ܵ������Զ���� 
			if(o[cnt+1].dis>tmpd){//��һվ�ڵ�ǰվ�����ܴﵽ�ľ���֮�� 
				printf("The maximum travel distance = %.2f",tmpd);
				return 0;
			}
			double pprice=o[cnt].price,lprice=o[cnt+1].price;//��ǰ�ͼۣ�����ͼ� 
			int flag=0,dest=cnt+1;
			for(int i=cnt+1;i<N+1;i++){//���ͼ���͵���һվ 
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
					break;//�������룬���� 
				}
			}
			if(flag){// ���ڱȵ�ǰ�۸�͵ļ���վ 
				cost+=((o[dest].dis-d)/Davg-tent)*o[cnt].price; //��Ŀ�ĵ��������� 
				d=o[dest].dis;//��Ŀ�ĵ�ʱ�ľ��� 
				tent=0;// ��Ŀ�ĵ�ʱ������ 
				cnt=dest;//Ŀ�ĵؼ���վ��� 
			}else{// �����ڱȵ�ǰ�۸�͵ļ���վ 
				cost+=(Cmax-tent)*o[cnt].price;//����������� 
				tent=Cmax-(o[dest].dis-d)/Davg;
				d=o[dest].dis;
				cnt=dest;
			}
		}
		printf("%.2f",cost);	
		
	}
	return 0;
}
