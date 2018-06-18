#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> v[10010];
int arr[10010][10010]; 
struct fri{
	int a,b;
	fri(int A,int B):a(A),b(B){};
};

bool cmp(fri p,fri q){
	if(p.a!=q.a){
		return p.a<q.a;
	}else{
		return p.b<q.b;
	}
}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		string a,b;
		cin>>a>>b;
		if(a.length()==b.length()){
			v[abs(stoi(a))].push_back(abs(stoi(b)));
			v[abs(stoi(b))].push_back(abs(stoi(a)));
		}
		arr[abs(stoi(b))][abs(stoi(a))]=arr[abs(stoi(a))][abs(stoi(b))]=1;
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		vector<fri> vff;
		int c,d;
		cin>>c>>d;
		for(int j=0;j<v[abs(c)].size();j++){
			for(int k=0;k<v[abs(d)].size();k++){
				if(v[abs(c)][j]==abs(d)||v[abs(d)][k]==abs(c))continue;
				if(arr[v[abs(c)][j]][v[abs(d)][k]]){
					vff.push_back(fri{v[abs(c)][j],v[abs(d)][k]});
				}
			}
		}
		sort(vff.begin(),vff.end(),cmp);
		printf("%d\n",vff.size());
		for(int i=0;i<vff.size();i++){
			printf("%04d %04d\n",vff[i].a,vff[i].b);
		}
	}
	return 0;
}
