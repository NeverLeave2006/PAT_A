#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

string s[]={"Qian","Bai","Shi","","Wang","Yi"};
string num[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
vector<string> v_s;

void read(int sws)//��λ�����ڵĶ���
{
	int n[10]={0},cnt=0;//Ϊʲô��4�������Խ�磬��10��û���⣡�������� 
	while(cnt<4){
		n[cnt++]=sws%10;
		sws/=10;
	}
	reverse(n,n+4);
	cnt=0;
	while(!n[cnt]&&cnt<4)cnt++;
	while(cnt<4){
		if(!n[cnt]){
			while(!n[cnt]&&cnt<4)cnt++;
			if(cnt<4){
				v_s.push_back("ling");//Ϊʲô�� 
				if(n[cnt]){
					v_s.push_back(num[n[cnt]]);
					v_s.push_back(s[cnt]);
				}
			}
			
			
		}
		else{
			v_s.push_back(num[n[cnt]]);
			v_s.push_back(s[cnt]);
		}
		cnt++; 
	}
	
 } 

int main()
{
	int a;
	scanf("%d",&a);
	if(a<0)v_s.push_back("Fu");
	a=abs(a);
	//��
	int tmp1=a/100000000;
	if(tmp1){
		read(tmp1); 
		v_s.push_back("Yi");
	}
	
	//��
	int sws=a/10000;
	sws=sws%10000;
	if(tmp1&&!(sws/1000)&&(a%100000000))v_s.push_back("ling");
	read(sws);
	if(sws)v_s.push_back("Wan");
	//�� 
	if(sws&&!((a%10000)/1000)&&(a%10000))v_s.push_back("ling");
	sws=a%10000;
	if(!a)v_s.push_back("ling");
	read(sws);
	//read(1001);
	vector<string>::iterator it=v_s.begin();
	while(it!=v_s.end()){
		cout<<*it;
		it++;
		if(it!=v_s.end()&&*it!="")cout<<" ";
		
	}
	return 0;
}
