#include <iostream>
#include <set>
using namespace std;

int book[50010]={0};
struct Node{
	int num;
	int cnt;
	Node(int n,int c):num(n),cnt(c){};
	bool operator < (const Node &a) const{
		return (cnt!=a.cnt)?cnt>a.cnt:num<a.num;
	}
};

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	set<Node> s;
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		if(i){
			printf("%d:",tmp);
			int cntK=0;
			for(auto it=s.begin();cntK<K&&it!=s.end();it++){
				printf(" %d",it->num);
				cntK++;
			}
			printf("\n");
		}
		auto it=s.find(Node(tmp,book[tmp]));
		if(it!=s.end())s.erase(it);
		book[tmp]++;
		s.insert(Node(tmp,book[tmp]));
	}
	return 0;
}
