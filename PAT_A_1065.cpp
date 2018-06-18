#include <iostream>
using namespace std;

int main()
{
	long long a,b,c,t;
	int Num;
	scanf("%d",&Num);
	for(int i=1;i<=Num;i++){
		bool flag=true;
		scanf("%lld %lld %lld",&a,&b,&c);
		t=a+b;
		if(a>0&&b>0&&t<=0)flag=true;
		else if(a<0&&b<0&&t>=0)flag=false;
		else if(t<=c){
			flag=false;
		}else{
			flag=true;
		}
		printf("Case #%d: %s\n",i,flag?"true":"false");
	}
	return 0;
}
