#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	map<string,string> ssMap;
	int cnt=0;
	vector<string> sVec;
 	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		
		int flag=0;
		for(int j=0;j<s2.length();j++){
			if(s2[j]=='1'){
				s2[j]='@';
				if(!flag)sVec.push_back(s1);
				flag=1;
			}
			if(s2[j]=='0'){
				s2[j]='%';
				if(!flag)sVec.push_back(s1);
				flag=1;
			}
			if(s2[j]=='l'){
				s2[j]='L';
				if(!flag)sVec.push_back(s1);
				flag=1;
			}
			if(s2[j]=='O'){
				s2[j]='o';
				if(!flag)sVec.push_back(s1);
				flag=1;
			}
			
		}
		ssMap[s1]=s2;
		if(flag)cnt++;
	}
	if(!cnt){
		if(n==1)puts("There is 1 account and no account is modified");
		else{
			printf("There are %d accounts and no account is modified\n",n);
		}
	}else{
		printf("%d\n",cnt);
		vector<string>::iterator it=sVec.begin();
		while(it!=sVec.end()){
			cout<<*it<<" "<<ssMap[*it]<<endl;
			//printf("%s %s\n",*it,ssMap[*it]);
			it++;
		}
	}
	
	return 0;
}
