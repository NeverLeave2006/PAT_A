#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int N,K,cnt=0;
int people[17576]={0},inq[17576]={0};
vector<int> nn[17576];
set<int> p;

int getID(string s){//¹þÏ£±í 
	int res=0;
	for(int i=0;i<3;i++){
		res*=26;
		res+=(s[i]-'A');
	} 
	return res; 
}

struct gg{
	int header;
	int size;
}ggg[2010];

bool cmp(gg a,gg b){
	return a.header<b.header;
}

void decode(int name){
	printf("%c",name/(26*26)+'A');
	name=name%(26*26);
	printf("%c",name/(26)+'A');
	name=name%(26);
	printf("%c",name+'A');
}

void BFS(int a,int &name,int &size){
	queue<int> Q;
	Q.push(a);
	inq[a]=1;
	set<int> gangs;
	gangs.insert(a);
	int sum=people[a];
	name=a;
	while(!Q.empty()){
		int t=Q.front();
		Q.pop();
		for(int i=0;i<nn[t].size();i++){
			if(!inq[nn[t][i]]){
				Q.push(nn[t][i]);
				inq[nn[t][i]]=1;
				gangs.insert(nn[t][i]);
				sum+=people[nn[t][i]];
				if(people[nn[t][i]]>people[name]){
					name=nn[t][i];
				}
			}
		}
	}
	if((sum/2)>K&&gangs.size()>2){
		size=gangs.size();
		cnt++;
	}
}

int main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		string a,b;
		cin>>a>>b;
		p.insert(getID(a));
		p.insert(getID(b));
		int time;
		scanf("%d",&time);
		people[getID(a)]+=time;
		people[getID(b)]+=time;
		nn[getID(a)].push_back(getID(b));
		nn[getID(b)].push_back(getID(a));
	}
	gg a[2010],ss[2010];
	for(set<int>::iterator it=p.begin();it!=p.end();it++){
		if(!inq[*it]){
			int name=-1,size=0;
			BFS(*it,name,size);
			if(size){
				ggg[cnt].header=name;
				ggg[cnt].size=size;
			}
		}
	}
	
	printf("%d\n",cnt);
	if(cnt){
		sort(ggg+1,ggg+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			decode(ggg[i].header);
			printf(" %d\n",ggg[i].size);
		}
	}
	return 0;
}
