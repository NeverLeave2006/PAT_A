#include <iostream>
#include <algorithm>
using namespace std;
int graph[210][210];
int v[210];
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d%d",&a,&b );
        graph[a][b]=1;
        graph[b][a]=1;
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int M;
        scanf("%d",&M);
        int begin,pre;
        int flag=1;
        if(M!=N+1)flag=0;
        fill(v,v+210,0);
        for(int j=0;j<M;j++){
            int tmp;
            scanf("%d",&tmp);
            if(j==0){
                begin=tmp;
                pre=tmp;
                continue;
            }
            if(flag){
                if(graph[tmp][pre]&&!v[tmp]){
                    v[tmp]=1;
                }else{
                    flag=0;
                }
                pre=tmp;
            }
        }
        printf(flag?"YES\n":"NO\n");
    }
    return 0;
}

