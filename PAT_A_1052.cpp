#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int addr;
	int val;
	int next;
};

map<int,Node> m_iN; 
vector<Node> v_N;

bool cmp(Node n1,Node n2){
	return n1.val<n2.val;
}

int main()
{
	int N,start;
	scanf("%d",&N);
	scanf("%d",&start);
	for(int i=0;i<N;i++){
		int tmp1,tmp2,tmp3;
		scanf("%d%d%d",&tmp1,&tmp2,&tmp3);
		Node tmp;
		tmp.addr=tmp1;
		tmp.val=tmp2;
		tmp.next=tmp3;
		m_iN[tmp1]=tmp;
	}
	while(start!=-1){
		Node tmp=m_iN[start];
		v_N.push_back(tmp);
		//printf("%05d %d %05d\n",tmp.addr,tmp.val,tmp.next);
		start=tmp.next;
	}
	printf("%d ",v_N.size());
	sort(v_N.begin(),v_N.end(),cmp);
	for(int i=0;i<v_N.size();i++){
		Node tmp=v_N[i];
		printf("%05d\n%05d %d ",tmp.addr,tmp.addr,tmp.val);
	}
	printf("-1");
	return 0;
}
