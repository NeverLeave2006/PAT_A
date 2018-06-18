#include <iostream>
#include <set>
using namespace std;

int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	set<char> rule;
	for(int i=0;i<b.length();i++){
		rule.insert(b[i]);
	}
	for(int i=0;i<a.length();i++){
		if(!rule.count(a[i]))printf("%c",a[i]);	
	}
	return 0;
 } 
