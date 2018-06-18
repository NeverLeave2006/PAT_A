#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int quota[110];//各个学院名额 
struct applicant{//申请者数据 
	int No;//编号 
	int Ge,Gi,sum;//GE,GI,总分 
	int rank;//排名 
	vector<int> choices;//志愿 
}nn[40010];
bool cmp(applicant a,applicant b)
{
	if(a.sum!=b.sum){
		return a.sum>b.sum;
	}else{
		return a.Ge>b.Ge;
	}
}
int Rank[110];//各个学院最低名次 
set<int> admission[110];//各个学院录取编号集合 
int main()
{
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++){
		scanf("%d",&quota[i]);
	}
	for(int i=0;i<N;i++){
		nn[i].No=i;
		scanf("%d%d",&nn[i].Ge,&nn[i].Gi);
		nn[i].sum=nn[i].Ge+nn[i].Gi;
		for(int j=0;j<K;j++){
			int tmp;
			scanf("%d",&tmp);
			nn[i].choices.push_back(tmp);
		}
	} 
	sort(nn,nn+N,cmp);
	nn[0].rank=0;
	for(int i=1;i<N;i++){//添加编号 
		if(nn[i].sum==nn[i-1].sum&&nn[i].Ge==nn[i-1].Ge){
			nn[i].rank=nn[i-1].rank;
		}else{
			nn[i].rank=i;
		}
	}
	for(int i=0;i<N;i++){//录取 
		for(int j=0;j<K;j++){
			if(quota[nn[i].choices[j]]){
				admission[nn[i].choices[j]].insert(nn[i].No);
				Rank[nn[i].choices[j]]=nn[i].rank;
				quota[nn[i].choices[j]]--;
				break;
			}else if(quota[nn[i].choices[j]]==0&&Rank[nn[i].choices[j]]==nn[i].rank){
				admission[nn[i].choices[j]].insert(nn[i].No);
				break;
			}
		} 
	}
	for(int i=0;i<M;i++){//输出 
		int j=0;
		for(auto it=admission[i].begin();it!=admission[i].end();it++){
			printf(j++==0?"%d":" %d",*it);
		}
		printf("\n");
	}
	return 0;
}
