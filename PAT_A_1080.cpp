#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int quota[110];//����ѧԺ���� 
struct applicant{//���������� 
	int No;//��� 
	int Ge,Gi,sum;//GE,GI,�ܷ� 
	int rank;//���� 
	vector<int> choices;//־Ը 
}nn[40010];
bool cmp(applicant a,applicant b)
{
	if(a.sum!=b.sum){
		return a.sum>b.sum;
	}else{
		return a.Ge>b.Ge;
	}
}
int Rank[110];//����ѧԺ������� 
set<int> admission[110];//����ѧԺ¼ȡ��ż��� 
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
	for(int i=1;i<N;i++){//��ӱ�� 
		if(nn[i].sum==nn[i-1].sum&&nn[i].Ge==nn[i-1].Ge){
			nn[i].rank=nn[i-1].rank;
		}else{
			nn[i].rank=i;
		}
	}
	for(int i=0;i<N;i++){//¼ȡ 
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
	for(int i=0;i<M;i++){//��� 
		int j=0;
		for(auto it=admission[i].begin();it!=admission[i].end();it++){
			printf(j++==0?"%d":" %d",*it);
		}
		printf("\n");
	}
	return 0;
}
