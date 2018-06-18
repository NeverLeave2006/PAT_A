#include <iostream>
#include <vector> 
using namespace std;

int main()
{
	int N,b;
	cin>>N>>b;
	vector<int> iVec;
	if(N==0){
		iVec.push_back(0);
	}
	while(N!=0){
		iVec.push_back(N%b);
		N/=b;
	} 
	int flag=0;
	for(int i=0;i<iVec.size()/2;i++){
		if(iVec[i]!=iVec[iVec.size()-i-1]){
			puts("No");
			flag=1;
			break;
		}
	}
	if(!flag)puts("Yes");
	vector<int>::iterator iter=iVec.end()-1;
	while(iter!=iVec.begin()-1){
		printf("%d",*iter);
		if(iter!=iVec.begin())printf(" ");
		iter--;
	}
	return 0;
}
