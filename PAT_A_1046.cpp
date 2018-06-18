#include <iostream>
#include <vector> 
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	vector<int> path;
	vector<int> dis;
	//int path[max];
	int sum=0;
	for(int i=0;i<N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		path.push_back(tmp);
		//path[i]=tmp;
		dis.push_back(sum);//´ò±í£¡£¡£¡£¡£¡£¡£¡ 
		sum+=tmp;	
	}
	int K;
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		int begin,end;
		scanf("%d%d",&begin,&end);
		if(begin>end)swap(begin,end);
		int s=dis[end-1]-dis[begin-1];
		printf("%d\n",s<(sum-s)?s:sum-s);
	}
	return 0;
}
