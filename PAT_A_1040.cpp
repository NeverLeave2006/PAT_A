#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;
int dp[1010][1010];

int main()
{
	string s;
	getline(cin,s);
	int len=s.length();
	memset(dp,0,sizeof(dp));
	int ans=1;
	for(int i=0;i<len;i++){//±ß½ç 
		dp[i][i]=1;
		if(i<len-1){
			if(s[i]==s[i+1]){
				dp[i][i+1]=1;
				ans=2;
			}
		}
	}
	for(int L=3;L<=len;L++){
		for(int i=0;i-1<len-L;i++){
			int j=i+L-1;
			if(s[i]==s[j]&&dp[i+1][j-1]==1){
				dp[i][j]=1;
				ans=L;
			}
		}
	} 
	printf("%d",ans);
	return 0;
}
