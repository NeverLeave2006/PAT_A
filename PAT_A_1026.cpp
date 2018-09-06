#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct persons{//此处不能用pair,重名 
	int arrive,play,servetime,waittime;
	bool tag;
};
struct table{
	int cnt=0;//桌子服务人数 
	int finishtime=8*3600;//结束时间 
};
bool cmp(persons a,persons b){//比较到达时间 
	return a.arrive<b.arrive;
}
bool cmp1(persons a,persons b){//比较开始服务时间 
	return a.servetime<b.servetime;
}
int main()
{
	int n,k,m;
	scanf("%d",&n);//读取用户数量 
	vector<persons> vp,res;
	for(int i=0;i<n;i++){//读取每个用户信息 
		int a,b,c,p,tag;
		scanf("%d:%d:%d %d %d",&a,&b,&c,&p,&tag);
		persons tmp;
		tmp.arrive=(a*60+b)*60+c;
		if(tmp.arrive>=21*3600)continue;//过滤21点以后到的 ，踩点到的也不想，奇葩测试点3，mdzz 
		if(p>120)p=120;//打球时间超过两个小时的压缩为两个小时 
		tmp.play=p*60;
		tmp.tag=(tag==1);
		vp.push_back(tmp);
	}
	scanf("%d%d",&k,&m);
	set<int> viptables;//记录VIP桌子 
	for(int i=0;i<m;i++){
		int tmpvip;
		scanf("%d",&tmpvip);
		viptables.insert(tmpvip);
	}
	///以上，数据输入部分 
	//初始化
	//persons按照到达时间排序
	sort(vp.begin(),vp.end(),cmp);
	//将vp视为队列
	vector<table> tables(k+1);//桌子集 
	while(vp.size()){//当接下来还有人来,模拟排队 
		int time=tables[1].finishtime,idx=1;
		persons tmp; //用于获取下一个用户信息 
		for(int i=2;i<=k;i++){//找结束时间最小的桌子
			if(time>tables[i].finishtime){
				idx=i;
				time=tables[i].finishtime;
			}
		}
		if(time>=21*3600){//如果结束时不能等到桌子 
			break; //结束这个循环 
		}else{//如果结束时能等到桌子 
			if(viptables.count(idx)){//如果这张是VIP桌子 
				vector<persons>::iterator it=vp.begin();//遍历指针 
				for(;it<vp.end();it++){//找到当时当前队列中的VIP 
					if(it->tag==true)break; 
				}
				if(it!=vp.end()&&it->arrive<=time){//当时存在VIP 
					tmp=*it;//获取其信息 
					vp.erase(it);//从队列中移除 
					int tmpidx=1;//用临时变量记录当前桌子 
					for(;tmpidx<=k;tmpidx++){//换到此时空着的序号最小的VIP桌子 ，遍历所有桌子 
						if(tables[tmpidx].finishtime<=tmp.arrive&&viptables.count(tmpidx))break;
					}
					if(tmpidx<=k){//存在空着的vip桌子 
						idx=tmpidx; 
					} 
				}else{//当时不存在VIP 
					tmp=vp[0];//获取下一个用户信息
					vp.erase(vp.begin());//从队列中移除 
					int tmpidx=1;//用临时变量记录当前桌子 
					for(;tmpidx<=k;tmpidx++){//换到此时空着的序号最小的桌子 ，遍历所有桌子 
						if(tables[tmpidx].finishtime<=tmp.arrive)break;
					}
					if(tmpidx<=k){//存在空着的桌子 
						idx=tmpidx; 
					} 
				}
				
			}else{//如果这张不是VIP桌子 
				tmp=vp[0]; //获取下一个用户信息 
				vp.erase(vp.begin());//从队列中移除
				if(tmp.tag==true){//用户是VIP球员 
					int tmpidx=1;//用临时变量记录当前桌子 
					for(;tmpidx<=k;tmpidx++){//换到此时空着的VIP桌子 ，遍历所有桌子 
						if(tables[tmpidx].finishtime<=tmp.arrive&&viptables.count(tmpidx))break;
					}
					if(tmpidx<=k){//存在空着的vip桌子 
						idx=tmpidx; 
					} 
				}else{//用户不是VIP球员 
					int tmpidx=1;//用临时变量记录当前桌子 
					for(;tmpidx<=k;tmpidx++){//换到此时空着的桌子 ，遍历所有桌子 
						if(tables[tmpidx].finishtime<=tmp.arrive)break;
					}
					if(tmpidx<=k){//存在空着的桌子 
						idx=tmpidx; 
					} 
				}
			}
			if(time<=tmp.arrive){//下一个用户到来前桌子已经空了 
				tmp.servetime=tmp.arrive;//更新用户信息 
				tmp.waittime=0;
				//更新桌面信息 
				tables[idx].finishtime=tmp.arrive+tmp.play;
			}else{//下一个用户到来前桌子还被占着 
				tmp.servetime=time;//更新用户信息 
				tmp.waittime=time-tmp.arrive;
				//更新桌面信息 
				tables[idx].finishtime=time+tmp.play;
			}
			tables[idx].cnt++;
			res.push_back(tmp);//获得服务的用户结果信息 
		}
	}
	sort(res.begin(),res.end(),cmp1);//结果排序 
	for(persons p:res){//输出结果 
		int ar=p.arrive,serv=p.servetime;
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",ar/3600,(ar%3600)/60,ar%60,serv/3600,(serv%3600)/60,serv%60,(p.waittime+30)/60);
	}
	for(int i=1;i<=k;i++){
		printf(i==1?"%d":" %d",tables[i].cnt); 
	}
	return 0;
}
