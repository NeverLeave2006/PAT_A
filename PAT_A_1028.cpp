#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct li{
	int No;
	char name[10];
	int score;
}nn[100010];

bool cmp1(li a,li b){
	return a.No<b.No;
}

bool cmp2(li a,li b){
	return strcmp(a.name,b.name)<=0;
}

bool cmp3(li a,li b){
	return a.score<=b.score;
}

int main()
{
	int N,C;
	scanf("%d%d",&N,&C);
	for(int i=0;i<N;i++){
		cin>>nn[i].No>>nn[i].name>>nn[i].score;
	}
	if(C==1){
		sort(nn,nn+N,cmp1);
	}else if(C==2){
		sort(nn,nn+N,cmp2);
	}else if(C==3){
		sort(nn,nn+N,cmp3);
	}
	for(int i=0;i<N;i++){
		printf("%06d %s %d\n",nn[i].No,nn[i].name,nn[i].score);
	}
	return 0;
}
