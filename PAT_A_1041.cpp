#include <iostream>
#include <set>
#include <vector> 
using namespace std;
int main()
{
	set<int> iSet;
	set<int> iSet2;
	vector<int> iVec;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		iVec.push_back(tmp);
		if(!iSet.count(tmp)){
			iSet.insert(tmp);
		} else{
			iSet2.insert(tmp);
		}
	}
	int flag=1;
	vector<int>::iterator it=iVec.begin();
	while(it!=iVec.end()){
		if(iSet.count(*it)&&!iSet2.count(*it)){
			printf("%d",*it);
			flag=0;
			break;
		}
		it++;
	}
	if(flag)puts("None");
	return 0;
 } 
