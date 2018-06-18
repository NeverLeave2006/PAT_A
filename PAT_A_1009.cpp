#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
	double res[2001]={0},a[1001]={0},b[1001]={0};
	int idxa[1001]={0},idxb[1001]={0},cnta=0,cntb=0;
	int N,M;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int idx;
		scanf("%d",&idx);
		idxa[cnta++]=idx;
		double tmp;
		scanf("%lf",&tmp);
		a[idx]=tmp;
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		int idx;
		scanf("%d",&idx);
		idxb[cntb++]=idx;
		double tmp;
		scanf("%lf",&tmp);
		b[idx]=tmp;
	}
	set<int> s_i;
	for(int i=0;i<cnta;i++){
		int ia=idxa[i];
		for(int j=0;j<cntb;j++){
			int ib=idxb[j];
			s_i.insert(ia+ib);
			res[ia+ib]+=a[ia]*b[ib];
		}
	}
	int cnt=0;
	for(int i=0;i<2001;i++){
		if(res[i]!=0.0)cnt++;
	}
	printf("%d",cnt);
	set<int>::iterator it=s_i.end();
	while(it!=s_i.begin()){
		it--;
		if(res[*it]!=0.0){
			printf(" %d %.1f",*it,res[*it]);
		}
	}
	return 0;
}
