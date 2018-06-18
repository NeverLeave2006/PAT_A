#include <iostream>
using namespace std;

int H2S(int h,int m,int s){
	return h*3600+m*60+s;
}

int main()
{
	int N;
	scanf("%d",&N);
	string first,end;
	int in=86400,out=0;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		getchar();
		int hh,mm,ss;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		int intmp=H2S(hh,mm,ss);
		scanf("%d:%d:%d",&hh,&mm,&ss);
		int outtmp=H2S(hh,mm,ss);
		if(intmp<in){
			first=s;
			in=intmp;
		}
		if(outtmp>out){
			end=s;
			out=outtmp;
		}
	}
	cout<<first<<" "<<end;
	return 0;
}
