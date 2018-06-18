#include <iostream>
#include <set>
using namespace std;

int cnt=0;

int calc(int x){
	int res=0;
	while(x!=0){
		res+=x%10;
		x/=10;
	}
	return res;
}

set<int> s_i;

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		int res=calc(tmp);
		s_i.insert(res);
		cnt++;
	}
	printf("%d\n",s_i.size());
	set<int>::iterator it=s_i.begin();
	while(it!=s_i.end()){
		if(it!=s_i.begin())printf(" ");
		printf("%d",*it);
		it++;
	}
	return 0;
}
