#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool equal(vector<int> a,vector<int> b){
	if(a.size()!=b.size())return false;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			return false;
		}
	}
	return true;
}

vector<int> Plus(vector<int> a,vector<int> b){
	vector<int> res;
	int tmp=0;
	for(int i=0;i<a.size();i++){
		int dig=a[i]+b[i]+tmp;
		res.push_back(dig%10);
		tmp=dig/10;
	}
	if(tmp)res.push_back(tmp);
	reverse(res.begin(),res.end());
	return res;
}

void Print(vector<int> a){
	for(int i=0;i<a.size();i++){
		printf("%d",a[i]);
	}
}

int main()
{
	long long N;
	int K;
	scanf("%lld%d",&N,&K);
	vector<int> a,b;
	while(N>0){
		int tmp=N%10;
		a.push_back(tmp);
		b.push_back(tmp);
		N/=10;
	}
	reverse(b.begin(),b.end());
	int cnt=0;
	while(!equal(a,b)){
		vector<int> res;
		res=Plus(a,b);
		a=res;
		reverse(res.begin(),res.end());
		b=res;
		cnt++;
		if(cnt>=K){
			break;
		}
	}
	Print(a);
	printf("\n%d",cnt);
	return 0;
}
