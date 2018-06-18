#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct richer{
	string name;
	int age;
	int Net_worth;
};

vector<richer> vr;//所有richer
vector<int> ags[201];
int selected[100010]; 
bool cmp(richer a,richer b){
	if(a.Net_worth!=b.Net_worth){
		return a.Net_worth>b.Net_worth;
	}else{
		if(a.age!=b.age){
			return a.age<b.age;
		}else{
			return a.name<b.name;
		}
	}
}

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		richer tmpR;
		int age;
		cin>>tmpR.name;
		scanf("%d%d",&tmpR.age,&tmpR.Net_worth);
		vr.push_back(tmpR);
	}
	sort(vr.begin(),vr.end(),cmp);
	for(int i=0;i<vr.size();i++){
		ags[vr[i].age].push_back(i);//记录每个序列上服务年龄的编号 
	}
	for(int i=1;i<=K;i++){
		printf("Case #%d:\n",i);
		int t,ag1,ag2;
		scanf("%d%d%d",&t,&ag1,&ag2);
		if(ag1>ag2)swap(ag1,ag2);
		fill(selected,selected+100010,0);
		int flag=0;
		for(int j=ag1;j<=ag2;j++){
			for(int k=0;k<ags[j].size()&&k<100;k++){
				selected[ags[j][k]]=1;
				flag++;
			}
		}
		if(!flag){
			printf("None\n");
		}else{
			int cntT=0;
			for(int j=0;j<100001&&cntT<t&&cntT<flag;j++){
				if(selected[j]){
					cout<<vr[j].name;
					printf(" %d %d\n",vr[j].age,vr[j].Net_worth);
					cntT++;
				}
			}
		}
	
	}
	return 0;
}
