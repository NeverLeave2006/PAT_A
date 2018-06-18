#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
	int M,N;
	scanf("%d%d",&M,&N);
	map<int,bool> inTree;
	vector<int> V(N);
	for(int i=0;i<N;i++){
		scanf("%d",&V[i]);
		inTree[V[i]]=true;
	}
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(inTree[u]==false&&inTree[v]==false){
			printf("ERROR: %d and %d are not found.\n",u,v);
		}else if(inTree[u]==false&&inTree[v]){
			printf("ERROR: %d is not found.\n",u);
		}else if(inTree[u]&&inTree[v]==false){
			printf("ERROR: %d is not found.\n",v);
		}else{
			for(int i=0;i<N;i++){
				if((V[i]>u&&V[i]<v)||(V[i]<u&&V[i]>v)){
					printf("LCA of %d and %d is %d.\n",u,v,V[i]);break;
				}else if(V[i]==u){
						printf("%d is an ancestor of %d.\n",u,v);break;
				}else if(V[i]==v){
						printf("%d is an ancestor of %d.\n",v,u);break;
				}
			}
		}
	}
	return 0;
}
