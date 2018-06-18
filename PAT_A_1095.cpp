#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct li{
	char No[10];
	int Times;
	char flag[5];
}car[10010];
struct proid{
	int inTime;
	int outTime;
	string No;
};
bool cmp(li a,li b){
	if(strcmp(a.No,b.No)){
		return strcmp(a.No,b.No)<0;
	}else{
		return a.Times<b.Times;
	}
}
bool cmp2(li a,li b){
	return a.Times<b.Times;
}
int carsNum[24*60*60+1];
set<string> vc;
vector<li> vli;
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		int h,m,s;
		scanf("%s %d:%d:%d %s",car[i].No,&h,&m,&s,car[i].flag);
		car[i].Times=((h*60)+m)*60+s;
	}
	sort(car,car+N,cmp);
	int ltime=0; 
	int period=0;
	for(int i=0;i<N-1;i++){
		if(!strcmp(car[i].No,car[i+1].No)){//同一辆车 
			if(!strcmp(car[i].flag,"in")&&!strcmp(car[i+1].flag,"out")){
				vli.push_back(car[i]);
				vli.push_back(car[i+1]);
				period+=(car[i+1].Times-car[i].Times);
			}
			if(period==ltime){
				vc.insert(car[i].No);
			}
			if(period>ltime){
				ltime=period;
				vc.clear();
				vc.insert(car[i].No);
			}
		}else{//不是同一辆车 
			period=0;
		}
	}
	sort(vli.begin(),vli.end(),cmp2);
	int t=0,pre=0;
	fill(carsNum,carsNum+(24*60*60+1),-1);
	for(int i=0;i<vli.size();i++){//写入发生数值变化的点 
		if(!strcmp(vli[i].flag,"in")){
			t++;
			carsNum[vli[i].Times]=t;
		}
		if(!strcmp(vli[i].flag,"out")){
			t--;
			carsNum[vli[i].Times]=t;
		}
	}
	t=0,pre=0;
	for(int i=0;i<(24*60*60+1);i++){//插值 
		if(carsNum[i]!=-1){
			for(int j=pre;j<i;j++){
				carsNum[j]=t;
			}
			pre=i;
			t=carsNum[i];
		}
	}
	for(int j=pre;j<(24*60*60+1);j++){
		carsNum[j]=t;
	}
	for(int i=0;i<K;i++){
		int h,m,s;
		scanf("%d:%d:%d",&h,&m,&s);
		printf("%d\n",carsNum[((h*60)+m)*60+s]);
	}
	for(auto it=vc.begin();it!=vc.end();it++){
		cout<<*it<<" ";
	}
	printf("%02d:%02d:%02d",ltime/3600,(ltime%3600)/60,ltime%60);
	return 0;
}
