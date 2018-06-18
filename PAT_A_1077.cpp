#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	vector<string> sVec;
	for(int i=0;i<N;i++){
		string tmp;
		getline(cin,tmp);
		sVec.push_back(tmp);
		
	}
	string cmp1=sVec[0];
	string cmp2=sVec[1];
	int flag=0;
	for(int i=1;i<=cmp1.length();i++){
		if(cmp1[cmp1.length()-i]==cmp2[cmp2.length()-i]){
			flag=i;
		}else{
			break;
		}
	}
	string ssss=cmp1.substr(cmp1.length()-flag);
	for(int i=2;i<sVec.size();i++){
		string tmp=sVec[i];
		for(int i=1;i<cmp1.length();i++){
			if(ssss[ssss.length()-i]==tmp[tmp.length()-i]){
				
			}else{
					flag=i-1;
					break;
			}
		}
	}
	ssss=cmp1.substr(cmp1.length()-flag);
	if(!flag){
		printf("nai");
	}else{
		cout<<ssss;
	}
	
	return 0;
}
