#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int M=26*26*26*10+1;
vector<int> list[M];

int getHash(char *s){
	int res=0;
	for(int i=0;i<3;i++){
		res*=26;
		res+=(s[i]-'A');
	}
	res=res*10+(s[3]-'0');
	return res;
}

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<K;i++){
		int k,n;
		scanf("%d%d",&k,&n);
		char s[5];
		for(int i=0;i<n;i++){
			scanf("%s",s);
			int index=getHash(s);
			list[index].push_back(k);
		} 
		
	}
	for(int i=0;i<N;i++){
		char s[5];
		scanf("%s",s);
		printf("%s ",s);
		int index=getHash(s);
		int size=list[index].size();
		printf("%d",size);
		sort(list[index].begin(),list[index].end());
		for(int j=0;j<size;j++){
			printf(" %d",list[index][j]);
		}
		printf("\n");
	}
	return 0;
}
