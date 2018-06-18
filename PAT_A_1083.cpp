#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	char name[12],id[13];
	int grade;
}stu[110];

vector<Node> v;
bool cmp(Node a,Node b){
	return a.grade>b.grade;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		cin>>stu[i].name>>stu[i].id>>stu[i].grade;
		//scanf("%s%s%d",stu[i].name,stu[i].id,stu[i].grade);
	}
	int g1,g2;
	scanf("%d%d",&g1,&g2);
	if(g1>g2)swap(g1,g2);
	for(int i=0;i<N;i++){
		if(stu[i].grade>=g1&&stu[i].grade<=g2){
			v.push_back(stu[i]);
		}
	}
	if(!v.empty()){
		sort(v.begin(),v.end(),cmp);
		for(vector<Node>::iterator it=v.begin();it!=v.end();it++){
			printf("%s %s\n",it->name,it->id);
		}
	}else{
		printf("NONE");
	}
	
	return 0;
}
