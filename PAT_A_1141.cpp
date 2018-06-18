#include <iostream>
#include <cctype>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct li{
	string s;
	int tws,Ns;
	li(string sch,int t,int N):s(sch),tws(t),Ns(N){};
};

map<string,double> tws;
map<string,int> NN;
vector<li> vli;

bool cmp(li a,li b){
	if(a.tws!=b.tws){
		return a.tws>b.tws;
	}else{
		if(a.Ns!=b.Ns){
			return a.Ns<b.Ns;
		}else{
			return a.s<b.s;
		}
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		double score;
		scanf("%lf",&score);
		if(s[0]=='T'){
			score*=1.5;
		}
		if(s[0]=='B'){
			score/=1.5;
		}
		getchar();
		string sch;
		cin>>sch;
		getchar();
		for(int i=0;i<sch.length();i++){
			sch[i]=tolower(sch[i]);
		}
		tws[sch]+=score;
		NN[sch]+=1;
	} 
	for(auto it=NN.begin();it!=NN.end();it++){
		vli.push_back(li(it->first,tws[it->first],NN[it->first]));
	}
	sort(vli.begin(),vli.end(),cmp);
	int mm=vli.size(),pre=1;
	printf("%d\n",mm);
	for(int i=0;i<mm;i++){
		if(i){
			if(vli[i].tws==vli[i-1].tws){
				printf("%d ",pre);
			}else{
				printf("%d ",i+1);
				pre=i+1;
			}
			cout<<vli[i].s;
			printf(" %d %d\n",vli[i].tws,vli[i].Ns);
		}else{
			printf("%d ",pre);
			cout<<vli[0].s;
			printf(" %d %d\n",vli[0].tws,vli[0].Ns);
		}
	}
	return 0;
}
