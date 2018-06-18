#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

struct feb{
	int sign;
	long long l;
	long long x,y;
};

feb f[101];

long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}


feb Plus(feb a,feb b){
	long long f=gcd(b.x,b.y);
	b.x/=f;
	b.y/=f;
	feb res;
	res.l=0;
	res.sign=0;
	res.x=a.x*b.y+a.y*b.x;
	res.y=a.y*b.y;
	long long g=gcd(res.x,res.y);
	res.x/=g;
	res.y/=g;
	return res;
}


void simp(feb &a){
	if((a.x<0&&a.y>0)||(a.x>0&&a.y<0)){
		a.sign=1;
	}
	a.x=abs(a.x);
	a.y=abs(a.y);
	a.l=a.x/a.y;
	a.x=a.x-a.y*a.l;
	long long g=gcd(a.x,a.y);
	a.x/=g;
	a.y/=g;
	
}

void print(feb s){
	if(s.sign)printf("-");
	if(s.l)printf("%lld",s.l);
	if(s.l&&s.x)printf(" ");
	if(s.x)printf("%lld/%lld",s.x,s.y);
	if(!s.l&&!s.x)printf("0"); //结果是0！！！第四个测试点！！！ 
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		feb tmp;
		tmp.l=0;
		tmp.sign=0;
		scanf("%lld/%lld",&tmp.x,&tmp.y);
		long long g=gcd(tmp.x,tmp.y);
		tmp.x/=g;
		tmp.y/=g;
		getchar();
		f[i]=tmp;
	}
	feb tmp=f[0];
	for(int i=1;i<N;i++){
		//printf("%lld/%lld ",f[i].x,f[i].y);
		tmp=Plus(tmp,f[i]);
	}
	simp(tmp);
	print(tmp);
	return 0;
}
