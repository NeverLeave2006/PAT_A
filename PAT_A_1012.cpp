#include <iostream>
#include <algorithm>
using namespace std;

struct li{
	int id,best;
	int score[4],rank[4];
}stu[2010];

int exist[1000010];

int N,M;
int flag=-1;

bool cmp(li a,li b){
	return a.score[flag]>b.score[flag];
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
		stu[i].score[0]=(int)((stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3.0);
	}
	for(int i=0;i<4;i++){
		flag=i;
		sort(stu,stu+N,cmp);
		stu[0].rank[flag]=1;//µÚÒ»Ãû 
		for(int j=1;j<N;j++){
			stu[j].rank[flag]=j+1;
			if(stu[j].score[flag]==stu[j-1].score[flag]){
				stu[j].rank[flag]=stu[j-1].rank[flag]; 
			}
		}
	}
	for(int i=0;i<N;i++){
		int min=stu[i].rank[0];
		stu[i].best=0;
		exist[stu[i].id]=i+1;
		for(int j=1;j<4;j++){
			if(min>stu[i].rank[j]){
				stu[i].best=j;
				min=stu[i].rank[j];
			}
		}
	}
	char Sign[]="ACME";
	for(int i=0;i<M;i++){
		int tmp;
		scanf("%d",&tmp);
		int ex=exist[tmp];
		if(ex){
			printf("%d %c\n",stu[ex-1].rank[stu[ex-1].best],Sign[stu[ex-1].best]);
		}else{
			printf("N/A\n");
		}
	}
	return 0;
}
