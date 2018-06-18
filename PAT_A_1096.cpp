#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	vector<int> iVec;
	int max=sqrt((double)N);
	for(int i=2;i<=max;i++){
		if(N%i==0)iVec.push_back(i);
	}
	iVec.push_back(N);
	vector<int>::iterator it=iVec.begin();
	int min=*it;
	int MaxNum=0; 
	while(it!=iVec.end()){
		int tmp=0;
		int tmpN=N;
		int tmpIT=*it;
		while(tmpN%(tmpIT)==0){
			tmpN/=tmpIT;
			tmp++;
			tmpIT++;
		}
		if(tmp>MaxNum){
			MaxNum=tmp;
			min=*it;
		}
		it++;
	}
	printf("%d\n",MaxNum?MaxNum:1);
	for(int i=0;i<MaxNum;i++){
		if(i)printf("*");
		printf("%d",min+i);
	}
 	return 0;
}
