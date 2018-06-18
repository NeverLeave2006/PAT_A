#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct logs{
	string name;
	int MM,dd,hh,mm,time,ttime;
	string state;
}ll[10010];

struct effectlogs{
	logs a,b;
};

int toll[24*60+1];

bool cmp(logs a,logs b){
	if(a.name!=b.name){
		return a.name<b.name;
	}else{
		return a.ttime<b.ttime;
	}
}

int main()
{
	toll[0]=0;
	for(int i=0;i<24;i++){
		int tmp;
		scanf("%d",&tmp);
		for(int j=1;j<=60;j++){
			toll[i*60+j]+=toll[i*60+j-1]+tmp;
		}
	}
//	for(int i=0;i<=24*60;i++){
//		printf("%d\n",toll[i]);
//	}
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		cin>>ll[i].name;
		scanf("%d:%d:%d:%d",&ll[i].MM,&ll[i].dd,&ll[i].hh,&ll[i].mm);
		ll[i].time=ll[i].mm+ll[i].hh*60;
		ll[i].ttime=ll[i].mm+ll[i].hh*60+ll[i].dd*24*60;
		cin>>ll[i].state;
	}
	sort(ll,ll+N,cmp);
//	for(int i=0;i<N;i++){
//		cout<<ll[i].name<<" "<<ll[i].MM<<" "<<ll[i].dd<<" "<<ll[i].hh<<" "<<ll[i].mm<<" "<<ll[i].state<<endl;;
//	}
	int cntN=1;
	while(cntN<N){
		string s=ll[cntN].name;
		
		vector<effectlogs> elog;
		while(ll[cntN].name==ll[cntN-1].name&&cntN<N){
			if(ll[cntN-1].state=="on-line"&&ll[cntN].state=="off-line"){
				effectlogs el{ll[cntN-1],ll[cntN]};
				elog.push_back(el);
			}
			cntN++;
		}
		if(elog.size()){
			cout<<s;
			printf(" %02d\n",ll[cntN-1].MM);
		}
		
		double TotalAmount=0;
		for(int i=0;i<elog.size();i++){
			effectlogs tt=elog[i];
			int time=tt.b.ttime-tt.a.ttime;
			double cost=0;
			int aa=tt.a.time,bb=tt.b.time;
			if(tt.a.dd==tt.b.dd){
				cost=toll[bb]-toll[aa];
			}else{
				cost=toll[24*60]-toll[aa]+(tt.b.dd-tt.a.dd-1)*toll[24*60]+toll[bb];
			}
			TotalAmount+=cost;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",tt.a.dd,tt.a.hh,tt.a.mm,tt.b.dd,tt.b.hh,tt.b.mm,time,cost/100);
		}
		
		if(elog.size())printf("Total amount: $%.2f\n",TotalAmount/100);
		cntN++;
	}
	return 0;
}
