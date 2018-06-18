#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a,string b){
	return a+b<b+a;
}

int main()
{
	vector<string> v_s;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		string tmp;
		cin>>tmp;
		v_s.push_back(tmp);
	}
	sort(v_s.begin(),v_s.end(),cmp);
	string res="";
	for(int i=0;i<N;i++){
		res+=v_s[i];
	}
	while(res[0]=='0')res.erase(res.begin());
	if(res.size())cout<<res;
	else cout<<"0";
	return 0;
}
