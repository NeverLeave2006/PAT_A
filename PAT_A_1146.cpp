#include <iostream>
#include <vector>
using namespace std;

vector<int > vec[1010];
vector<int> in(1010,0),incpy,res;

int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		vec[a].push_back(b);
		in[b]++;
	}
	int mm;
	scanf("%d",&mm);
	int flag=0;
	for(int i=0;i<mm;i++){
		flag=0;
		incpy=in;
		for(int j=0;j<m;j++){
			int t;
			scanf("%d",&t);
			if(incpy[t]!=0){
				flag=1;
			}
			for(int tmp:vec[t]){
				incpy[tmp]--;
			}
		}
		if(flag)res.push_back(i);
	}
	for(int i=0;i<res.size();i++){
		printf(i?" ":"");
		printf("%d",res[i]);
		
	}
	return 0;
}
