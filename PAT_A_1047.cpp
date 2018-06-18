#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

char name[40010][5];
vector<int> course[2510];

bool cmp(int a,int b){
	return strcmp(name[a],name[b])<0;
}

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		int n;
		scanf("%s %d",name[i],&n);
		for(int j=0;j<n;j++){
			int c;
			scanf("%d",&c);
			course[c].push_back(i);
		}
	}
	for(int i=1;i<=K;i++){
		int size=course[i].size();
		printf("%d %d\n",i,size);
		sort(course[i].begin(),course[i].end(),cmp);
		for(int j=0;j<size;j++){
			printf("%s\n",name[course[i][j]]);
		}
	}
	return 0;
}
