#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
	int k;
	scanf("%d",&k);
	string s;
	getchar();
	getline(cin,s);
	int cnt=1;
	set<char> s_c1,s_c2;
	vector<char> v_c;
	for(int i=0;i<s.length();i++){
		if(i){
			if(s[i]==s[i-1]){
				cnt++;
			}else{
				if(cnt%k!=0)s_c1.insert(s[i-1]);
				cnt=1;
			}
			if((i==s.length()-1)){//结尾不是坏键 
				if(cnt%k!=0||s[i]!=s[i-1]){//结尾不是坏键 
					s_c1.insert(s[i]);
				}
			}
		}
	}
	for(int i=0;i<s.length();i++){
    	if(s_c1.count((s[i]))==0&&s_c2.count(s[i])==0){
      		s_c2.insert(s[i]);
      		v_c.push_back(s[i]);
    	}
  	}
	vector<char>::iterator it=v_c.begin();
	while(it!=v_c.end()){
		printf("%c",*it);
		it++;
	}
	printf("\n");
	for(int i=0;i<s.length();i++){
		printf("%c",s[i]);
		if(s_c2.count(s[i]))i+=k-1;
	}
	return 0;
}
