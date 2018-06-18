#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	vector<int> iVec;
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		iVec.push_back(tmp);
	}
	int Max=0,i1=0,j1=iVec.size()-1;
	for(int i=0;i<=iVec.size();i++){
		int tmpSum=0;
		for(int j=i;j<=iVec.size();j++){
			tmpSum+=iVec[j];
			if(tmpSum>Max){
				Max=tmpSum;
				i1=i;
				j1=j;
			}
		}
		
	}
	printf("%d %d %d",Max,i1,j1);
	return 0;
}
