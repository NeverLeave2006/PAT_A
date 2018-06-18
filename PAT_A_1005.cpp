#include <iostream>
#include <stack>
using namespace std;

int main(){
	string I;
	getline(cin,I);
	int sum=0;
	for(int i=0;i<I.length();i++){
		sum+=(I[i]-'0');
	}
	//cout<<sum;
	stack<int> q;
	if(sum==0)cout<<"zero";//±ß½ç²âÊÔ 
 	while(sum!=0){
		int tmp=sum%10;
		q.push(tmp);
		sum/=10;
	}
	string list[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	
	while(!q.empty()){
		cout<<list[q.top()];
		q.pop();
		if(!q.empty())cout<<" ";
	}
	return 0;
}
