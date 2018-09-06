#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
struct node{
	int poptime,endtime;
	queue<int> q;
};
int main()
{
	int n,m,k,q,index=1;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	vector<int> time(k+1),result(k+1);
	vector<bool> sorry(k+1,false);
	for(int i=1;i<=k;i++){
		scanf("%d",&time[i]);
	} 
	vector<node> vn(n+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(index<=k){
				vn[j].q.push(time[index]);
				if(vn[j].endtime>=540)
					sorry[index]=true;
				vn[j].endtime+=time[index];
				if(i==1)
					vn[j].poptime=vn[j].endtime;
				result[index]=vn[j].endtime;
				index++;
			}
		}
	}
	while(index<=k){
		int tmptime=vn[1].poptime,idx=1;
		for(int i=2;i<=n;i++){
			if(vn[i].poptime<tmptime){
				tmptime=vn[i].poptime;
				idx=i;
			}
		}
		vn[idx].q.pop();
		vn[idx].q.push(time[index]);
		vn[idx].poptime+=vn[idx].q.front();
		if(vn[idx].endtime>=540)
			sorry[index]=true;
		vn[idx].endtime+=time[index];
		result[index]=vn[idx].endtime;
		index++;
	}
	while(q--){
		int tmp;
		scanf("%d",&tmp);
		if(sorry[tmp]){
			printf("Sorry\n");
		}else{
			int t=result[tmp];
			printf("%02d:%02d\n",(480+t)/60,(480+t)%60);
		}
	}
	return 0;
} 
