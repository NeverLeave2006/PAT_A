#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct usr{//用户时间信息 
	int arrive,time;
}user[10010];
bool cmp(usr a,usr b){
	return a.arrive<b.arrive;
}
int main()
{
	int n,k,cnt=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d:%d:%d %d",&a,&b,&c,&user[cnt].time);
		int time=(a*60+b)*60+c;
		if(time>17*3600)continue;//排除干扰项 
		user[cnt].arrive=time;
		user[cnt].time*=60;
		cnt++;//有效项目 
	}
	vector<int> window(k,8*3600);
	sort(user,user+cnt,cmp);
	double sum=0.0;
	for(int i=0;i<cnt;i++){//早到的累计时间 
		int tmpidx=0,mintime=window[0];
		for(int j=1;j<k;j++){
			if(mintime>window[j]){//记录最早完成窗口 
				mintime=window[j];
				tmpidx=j;
			}
		}
		if(window[tmpidx]<=user[i].arrive){//客人到时没有人 
			window[tmpidx]=user[i].arrive+user[i].time; 
		} else{//客人到时有人 
			sum+=(window[tmpidx]-user[i].arrive);
			window[tmpidx]+=user[i].time;
		}
	}
	printf(cnt?"%.1f":"0.0",sum/60.0/cnt);
	return 0;
}
