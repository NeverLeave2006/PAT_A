#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
	string N;
	getline(cin,N);
	set<int> iSet;
	vector<int> iVec1; 
	int a[10]={0};
	int b[10]={0};
	for(int i=N.length()-1;i>=0;i--){
		int tmp=N[i]-'0';
		a[tmp]++;
		iSet.insert(tmp);
		iVec1.push_back(tmp);
	}
	vector<int> iVec2(iVec1); 
	
	
	int digt=0,flag=0;
	for(int i=0;i<N.length();i++){
		int tmp=iVec2[i];
		tmp*=2;
		tmp+=digt;
		iVec2[i]=tmp%10;
		b[tmp%10]++;
		if(!iSet.count(tmp%10)){
			flag=1;
		}
		digt=tmp/10;
	}
	if(digt!=0){
		iVec2.push_back(digt);
		flag=1;
	}
	
	for(int i=0;i<10;i++){
		if(a[i]!=b[i]){
			flag=1;
			break;
		}
	}
	
	if(flag==1){
		puts("No");
	}else{
		puts("Yes");
	}
	
	
	vector<int>::iterator iter=iVec2.end()-1;
	while(iter!=iVec2.begin()-1){
		cout<<*iter;
		iter--;
	}
	
	return 0;
}
