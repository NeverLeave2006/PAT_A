#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> pp,pn,cp,cn; 

bool cmp(int a,int b){
	return abs(a)>abs(b);
}

void range(){
	sort(pp.begin(),pp.end(),cmp);
	sort(pn.begin(),pn.end(),cmp);
	sort(cp.begin(),cp.end(),cmp);
	sort(cn.begin(),cn.end(),cmp);
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int tmp=0;
		scanf("%d",&tmp);
		if(tmp>0){
			pp.push_back(tmp);
		}
		if(tmp<0){
			pn.push_back(tmp);
		}
	}
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int tmp=0;
		scanf("%d",&tmp);
		if(tmp>0){
			cp.push_back(tmp);
		}
		if(tmp<0){
			cn.push_back(tmp);
		}
	}
	range();
	int sum=0;
	for(int i=0;(i<cp.size())&&(i<pp.size());i++){
		sum+=cp[i]*pp[i];
	}
	for(int i=0;(i<cn.size())&&(i<pn.size());i++){
		sum+=cn[i]*pn[i];
	}
	printf("%d",sum);
	return 0;
}
