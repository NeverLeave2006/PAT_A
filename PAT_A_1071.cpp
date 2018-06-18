#include <iostream>
#include <map>
using namespace std;

bool check(char c){//检查是否有效字符 
	if(c>='a'&&c<='z')return true;
	if(c>='A'&&c<='Z')return true;
	if(c>='0'&&c<='9')return true;
	return false;
}

map<string,int> m_si;

int main()
{
	string s;
	getline(cin,s);
	for(int i=0;i<s.length();i++){//大写改小写 
		if(s[i]>='A'&&s[i]<='Z'){
			s[i]+=('a'-'A');
		}
	}
	int k=0;
	while(k<s.length()){
		while(!check(s[k])&&k<s.length()){
			k++;
		}
		string word="";
		while(check(s[k])&&k<s.length()){
			word+=s[k++];
		}
		m_si[word]++;
	}
	string ans;
	int max=0;
	for(map<string,int>::iterator it=m_si.begin();it!=m_si.end();it++){
		if(it->second>max){
			ans=it->first;
			max=it->second;
		}
	} 
	cout<<ans<<" "<<max;
	return 0;
}
