#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int scores[10];

struct stu{
	int id;
	int scores[7];
	int totolScore;
	int flag,cnt;
}ss[10010];


bool cmp(stu a,stu b){
	if(a.cnt!=b.cnt){
		return a.cnt>b.cnt;//编译通过的先输出 
	}else{
		if(a.totolScore!=b.totolScore){
			return a.totolScore>b.totolScore;
		}else{
			if(a.flag!=b.flag){
				return a.flag>b.flag;
			}else{
				return a.id<b.id;
			}
		}
	}	
}

int main()
{
	int N,K,M;
	scanf("%d%d%d",&N,&K,&M);
	for(int i=1;i<=K;i++){
		scanf("%d",&scores[i]);
	}
	for(int i=1;i<=N;i++){
		for(int j=0;j<7;j++){
			ss[i].scores[j]=-2;
		}
		ss[i].id=i; 
		ss[i].totolScore=0;
		ss[i].flag=0;
		ss[i].cnt=0;
	}
	for(int i=0;i<M;i++){
		int id,pId,sc;
		scanf("%d%d%d",&id,&pId,&sc);
		if(ss[id].scores[pId]<sc){//提交后分数变高了 
			if(ss[id].scores[pId]!=-2){//提交了编译通过了的初始化 
				ss[id].totolScore-=ss[id].scores[pId];//分数还原 
			}
			if(sc==scores[pId]){//完美解决计数 
				ss[id].flag++;
			}
			if(sc!=-1){//通过编译 
				ss[id].scores[pId]=sc; 
				ss[id].totolScore+=sc;
				ss[id].cnt=1;
			}else{//未通过 
				ss[id].scores[pId]=0;
				
			}
		}
	}
	sort(ss+1,ss+N+1,cmp);
	int pre=1;
	for(int i=1;i<=N;i++){
		if(!ss[i].cnt)break;
		if(ss[i].totolScore!=ss[i-1].totolScore&&i!=1){
			pre=i;
		}
		printf("%d %05d %d",pre,ss[i].id,ss[i].totolScore);
		for(int j=1;j<=K;j++){
			printf(ss[i].scores[j]==-2?" -":" %d",ss[i].scores[j]);
		}
		printf("\n");
		
	}
	return 0;
}
