#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct usr{//�û�ʱ����Ϣ 
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
		if(time>17*3600)continue;//�ų������� 
		user[cnt].arrive=time;
		user[cnt].time*=60;
		cnt++;//��Ч��Ŀ 
	}
	vector<int> window(k,8*3600);
	sort(user,user+cnt,cmp);
	double sum=0.0;
	for(int i=0;i<cnt;i++){//�絽���ۼ�ʱ�� 
		int tmpidx=0,mintime=window[0];
		for(int j=1;j<k;j++){
			if(mintime>window[j]){//��¼������ɴ��� 
				mintime=window[j];
				tmpidx=j;
			}
		}
		if(window[tmpidx]<=user[i].arrive){//���˵�ʱû���� 
			window[tmpidx]=user[i].arrive+user[i].time; 
		} else{//���˵�ʱ���� 
			sum+=(window[tmpidx]-user[i].arrive);
			window[tmpidx]+=user[i].time;
		}
	}
	printf(cnt?"%.1f":"0.0",sum/60.0/cnt);
	return 0;
}
