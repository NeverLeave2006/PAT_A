#include <iostream>
using namespace std;
double poly[1010];
int cnt=0,max=0;
int void main()
{
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int a;
        double b;
        cin>>a>>b;
        p[a]=b;
        if(a>max)max=a;//找最大项
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int a;
        double b;
        cin>>a>>b;
        p[a]+=b;
        if(a>max)max=a;//找最大项
    }
    for(int i=max;i>0;i--)cnt++;//非零项计数

    return 0;
}
