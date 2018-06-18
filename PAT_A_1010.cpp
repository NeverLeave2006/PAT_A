#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
long long inf = (1LL << 63)-1;

map<char,int> m_ci;
long long convert(string a,long long radix,long long t){//转换函数 
	long long res=0;
	for(int i=0;i<a.length();i++){
		res*=radix;
		res+=m_ci[a[i]];
		if(res>t||res<0)return -1;
	}
	
	return res;
}

int find_max(string a){
	int max=0;
	for(int i=0;i<a.length();i++){
		if(m_ci[a[i]]+1>max){
			max=m_ci[a[i]]+1;
		}
	}
	return max;
}

int cmp(string N2,long long radix,long long t){
	int len=N2.length();
	long long num=convert(N2,radix,t);
	if(num<0)return 1;//溢出，N2>t
	if(t>num)return -1;//t大 
	else if(t==num)return 0;//相等 
	else return 1; //num大 
}

long long bisearch(string N2,long long lbound,long long hbound,long long t){
	long long mid;
	while(lbound<=hbound){
			mid=(lbound+hbound)/2;
			int flag=cmp(N2,mid,t);
			if(flag==0){
				return mid;
			}else if(flag==-1){
				lbound=mid+1;
			}else{
				hbound=mid-1;
			}
	}
	return -1;
			
}

int main()
{
	for(int i=0;i<10;i++){
		m_ci[('0'+i)]=i;
	}
	for(int i=0;i<26;i++){
		m_ci[('a'+i)]=i+10;
	}//初始化 
	string a,b;
	cin>>a>>b;
	long long tag,radix;
	scanf("%lld %lld",&tag,&radix);
	if(tag==2){
		swap(a,b);
	}
	long long t=convert(a,radix,inf);
	long long lbound=find_max(b);
	long long hbound=lbound>t?(lbound+1):(t+1);
	if(lbound>hbound){
		printf("Impossible");
		return 0;
	}else{
		long long r=bisearch(b,lbound,hbound,t);
		if(r<0)printf("Impossible");
		else printf("%lld",r);
	}
	return 0;
}
