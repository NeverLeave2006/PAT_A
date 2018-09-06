#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct persons{//�˴�������pair,���� 
	int arrive,play,servetime,waittime;
	bool tag;
};
struct table{
	int cnt=0;//���ӷ������� 
	int finishtime=8*3600;//����ʱ�� 
};
bool cmp(persons a,persons b){//�Ƚϵ���ʱ�� 
	return a.arrive<b.arrive;
}
bool cmp1(persons a,persons b){//�ȽϿ�ʼ����ʱ�� 
	return a.servetime<b.servetime;
}
int main()
{
	int n,k,m;
	scanf("%d",&n);//��ȡ�û����� 
	vector<persons> vp,res;
	for(int i=0;i<n;i++){//��ȡÿ���û���Ϣ 
		int a,b,c,p,tag;
		scanf("%d:%d:%d %d %d",&a,&b,&c,&p,&tag);
		persons tmp;
		tmp.arrive=(a*60+b)*60+c;
		if(tmp.arrive>=21*3600)continue;//����21���Ժ󵽵� ���ȵ㵽��Ҳ���룬������Ե�3��mdzz 
		if(p>120)p=120;//����ʱ�䳬������Сʱ��ѹ��Ϊ����Сʱ 
		tmp.play=p*60;
		tmp.tag=(tag==1);
		vp.push_back(tmp);
	}
	scanf("%d%d",&k,&m);
	set<int> viptables;//��¼VIP���� 
	for(int i=0;i<m;i++){
		int tmpvip;
		scanf("%d",&tmpvip);
		viptables.insert(tmpvip);
	}
	///���ϣ��������벿�� 
	//��ʼ��
	//persons���յ���ʱ������
	sort(vp.begin(),vp.end(),cmp);
	//��vp��Ϊ����
	vector<table> tables(k+1);//���Ӽ� 
	while(vp.size()){//����������������,ģ���Ŷ� 
		int time=tables[1].finishtime,idx=1;
		persons tmp; //���ڻ�ȡ��һ���û���Ϣ 
		for(int i=2;i<=k;i++){//�ҽ���ʱ����С������
			if(time>tables[i].finishtime){
				idx=i;
				time=tables[i].finishtime;
			}
		}
		if(time>=21*3600){//�������ʱ���ܵȵ����� 
			break; //�������ѭ�� 
		}else{//�������ʱ�ܵȵ����� 
			if(viptables.count(idx)){//���������VIP���� 
				vector<persons>::iterator it=vp.begin();//����ָ�� 
				for(;it<vp.end();it++){//�ҵ���ʱ��ǰ�����е�VIP 
					if(it->tag==true)break; 
				}
				if(it!=vp.end()&&it->arrive<=time){//��ʱ����VIP 
					tmp=*it;//��ȡ����Ϣ 
					vp.erase(it);//�Ӷ������Ƴ� 
					int tmpidx=1;//����ʱ������¼��ǰ���� 
					for(;tmpidx<=k;tmpidx++){//������ʱ���ŵ������С��VIP���� �������������� 
						if(tables[tmpidx].finishtime<=tmp.arrive&&viptables.count(tmpidx))break;
					}
					if(tmpidx<=k){//���ڿ��ŵ�vip���� 
						idx=tmpidx; 
					} 
				}else{//��ʱ������VIP 
					tmp=vp[0];//��ȡ��һ���û���Ϣ
					vp.erase(vp.begin());//�Ӷ������Ƴ� 
					int tmpidx=1;//����ʱ������¼��ǰ���� 
					for(;tmpidx<=k;tmpidx++){//������ʱ���ŵ������С������ �������������� 
						if(tables[tmpidx].finishtime<=tmp.arrive)break;
					}
					if(tmpidx<=k){//���ڿ��ŵ����� 
						idx=tmpidx; 
					} 
				}
				
			}else{//������Ų���VIP���� 
				tmp=vp[0]; //��ȡ��һ���û���Ϣ 
				vp.erase(vp.begin());//�Ӷ������Ƴ�
				if(tmp.tag==true){//�û���VIP��Ա 
					int tmpidx=1;//����ʱ������¼��ǰ���� 
					for(;tmpidx<=k;tmpidx++){//������ʱ���ŵ�VIP���� �������������� 
						if(tables[tmpidx].finishtime<=tmp.arrive&&viptables.count(tmpidx))break;
					}
					if(tmpidx<=k){//���ڿ��ŵ�vip���� 
						idx=tmpidx; 
					} 
				}else{//�û�����VIP��Ա 
					int tmpidx=1;//����ʱ������¼��ǰ���� 
					for(;tmpidx<=k;tmpidx++){//������ʱ���ŵ����� �������������� 
						if(tables[tmpidx].finishtime<=tmp.arrive)break;
					}
					if(tmpidx<=k){//���ڿ��ŵ����� 
						idx=tmpidx; 
					} 
				}
			}
			if(time<=tmp.arrive){//��һ���û�����ǰ�����Ѿ����� 
				tmp.servetime=tmp.arrive;//�����û���Ϣ 
				tmp.waittime=0;
				//����������Ϣ 
				tables[idx].finishtime=tmp.arrive+tmp.play;
			}else{//��һ���û�����ǰ���ӻ���ռ�� 
				tmp.servetime=time;//�����û���Ϣ 
				tmp.waittime=time-tmp.arrive;
				//����������Ϣ 
				tables[idx].finishtime=time+tmp.play;
			}
			tables[idx].cnt++;
			res.push_back(tmp);//��÷�����û������Ϣ 
		}
	}
	sort(res.begin(),res.end(),cmp1);//������� 
	for(persons p:res){//������ 
		int ar=p.arrive,serv=p.servetime;
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",ar/3600,(ar%3600)/60,ar%60,serv/3600,(serv%3600)/60,serv%60,(p.waittime+30)/60);
	}
	for(int i=1;i<=k;i++){
		printf(i==1?"%d":" %d",tables[i].cnt); 
	}
	return 0;
}
