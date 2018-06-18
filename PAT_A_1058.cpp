#include <iostream>
using namespace std;

int main()
{
  long long sum1,sum2;
  long long G,S,K;
  scanf("%lld.%lld.%lld",&G,&S,&K);
  sum1=G*17*29+S*29+K;
  scanf("%lld.%lld.%lld",&G,&S,&K);
  sum2=G*17*29+S*29+K;
  long long sum=sum1+sum2;
  G=sum/(17*29);
  S=(sum/29)%17;
  K=sum%29;
  printf("%lld.%lld.%lld",G,S,K);
  return 0;
 } 
