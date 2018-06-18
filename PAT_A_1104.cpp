#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int N;
	cin>>N;
	double sum=0;
	for(int i=0;i<N;i++)
	{
		double tmp;
		cin>>tmp;
		sum+=tmp*(i+1)*(N-i);
	}
	printf("%.2f",sum);
	return 0;
}
