#include <cstdio>
#include <set>
using namespace std;

set<int> Si[60];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int n;
		scanf("%d",&n);
		for(int j=0;j<n;j++){
			int tmp;
			scanf("%d",&tmp);
			Si[i].insert(tmp);
		}
	}
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		int sum=Si[a].size()+Si[b].size();
		int cnt=0;
		set<int>::iterator it=Si[a].begin();
		while(it!=Si[a].end()){
			if(Si[b].count(*it)){
				cnt++;
			}
			it++;
		}
		printf("%.1f%%\n",cnt*100.0/(sum-cnt));
	}
	return 0;
}
