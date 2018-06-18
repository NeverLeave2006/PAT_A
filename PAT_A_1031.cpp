#include <iostream>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	int n1=(s.length()+2)/3,n2=s.length()+2-2*n1;
	for(int i=0;i<n1-1;i++){
		for(int j=0;j<n2;j++){
			if(j==0)printf("%c",s[i]);
			else if(j==n2-1){
				printf("%c",s[s.length()-1-i]);
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	for(int j=0;j<n2;j++){
		printf("%c",s[n1+j-1]);
	}
	return 0;
}
