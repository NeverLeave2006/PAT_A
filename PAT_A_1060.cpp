#include <iostream>
#include <string>
using namespace std;

int N;//机器精度 

string deal(string a,int &e){
	int k=0;//下标 
	while(a[0]=='0'&&a.length()>0){
		a.erase(a.begin());
	}
	if(a[0]=='.'){//找小数点 
		a.erase(a.begin());
		while(a[0]=='0'&&a.length()>0){
			a.erase(a.begin());
			e--;
		}			
	}else{
		while(k<a.length()&&a[k]!='.'){
			k++;
			e++;
		}
		if(k<a.length()){//如果遇到小数点 
			a.erase(a.begin()+k);//移除小数点 
		}
	} 
	if(a.length()==0){
		e=0;
	}
	int num=0;
	k=0;
	string res;
	while(num<N){
		if(k<a.length())res+=a[k++];
		else res+='0';
		num++; 
	}
	return res;
}

int main()
{
	scanf("%d",&N);
	string a,b,c,d;
	cin>>a>>b;
	int e1=0,e2=0;
	c=deal(a,e1);
	d=deal(b,e2);
	if(c==d&&e1==e2){
		cout<<"YES 0."<<c<<"*10^"<<e1<<endl;
	}else{
		cout<<"NO 0."<<c<<"*10^"<<e1<<" 0."<<d<<"*10^"<<e2<<endl;
	}
	return 0;
}
