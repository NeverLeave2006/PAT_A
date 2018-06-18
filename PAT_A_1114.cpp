#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
struct family_properties{
	int ID;
	int M;//家族人数 
	double sets;
	double area; 
};
set<int> members;
set<int> si;
map<int,family_properties> mif;
vector<family_properties> vf;
int people[10010];
bool cmp(family_properties fa,family_properties fb){
	if((fa.area/fa.M)!=(fb.area/fb.M)){
		return (fa.area/fa.M)>(fb.area/fb.M);
	}else{
		return fa.ID<fb.ID;
	}
}
int main()
{
	for(int i=0;i<10010;i++){//初始化 
		people[i]=i;
	}
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){//读入数据，完成并查集 
		int ID,Father,Mother,k;
		scanf("%d%d%d%d",&ID,&Father,&Mother,&k);
		members.insert(ID);
		int id=ID;//保存原ID 
		while(people[ID]!=ID){
			ID=people[ID];
		}
		if(Father!=-1){
			members.insert(Father);
			while(people[Father]!=Father){
				Father=people[Father];
			}
			people[Father]=ID;
		}
		if(Mother!=-1){
			members.insert(Mother);
			while(people[Mother]!=Mother){
				Mother=people[Mother];
			}
			people[Mother]=ID;
		}
		for(int j=0;j<k;j++){
			int tmp;
			scanf("%d",&tmp);
			members.insert(tmp);
			while(people[tmp]!=tmp){
				tmp=people[tmp];
			}
			people[tmp]=ID;
		}
		double sets;
		double area;
		scanf("%lf%lf",&sets,&area);
		mif[id]={id,0,sets,area};
	}
	for(auto it=members.begin();it!=members.end();it++){//统计家族数，家族资产，家族人口 
		int m=*it;
		while(people[m]!=m){
			m=people[m];
		}
		si.insert(m);
		if(mif.count(*it)&&m!=*it){
			family_properties f=mif[*it];
			mif[m].sets+=f.sets;
			mif[m].area+=f.area;
		}
		mif[m].M+=1;
		if((*it)<mif[m].ID){
			mif[m].ID=*it;
		} 
	}
	printf("%d\n",si.size());
	for(auto it=si.begin();it!=si.end();it++){
		vf.push_back(mif[*it]);
	}
	sort(vf.begin(),vf.end(),cmp);
	for(auto it=vf.begin();it!=vf.end();it++){
		printf("%04d %d %.3f %.3f\n",it->ID,it->M,it->sets/it->M,it->area/it->M);
	}
	return 0;
 } 
