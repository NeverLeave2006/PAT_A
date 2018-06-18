#include <iostream>
#include <map>
using namespace std;
int main()
{
	string arr1="0123456789ABC";
	map<int,char> ciMap1;
	for(int i=0;i<arr1.length();i++){
		ciMap1[i]=arr1[i];
	}
	for(int i=0;i<3;i++){
		int tmp;
		scanf("%d",&tmp);
		if(!i)printf("#");
		printf("%c%c",ciMap1[tmp/13],ciMap1[tmp%13]);
	}
	return 0;
}
