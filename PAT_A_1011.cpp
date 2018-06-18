#include <iostream>
using namespace std;

int main()
{
	double benefit=1;
	for(int i=0;i<3;i++){
		double tmp1,tmp2,tmp3;
		cin>>tmp1>>tmp2>>tmp3;
		if(tmp1>tmp2&&tmp1>tmp3){
			printf("W ");
			benefit*=tmp1;
		}
		else if(tmp2>tmp1&&tmp2>tmp3){
			printf("T ");
			benefit*=tmp2;
		}else{
			printf("L ");
			benefit*=tmp3;
		}
	}
	benefit*=0.65;
	benefit-=1;
	benefit*=2;
	if(benefit*1000-(int)(benefit*1000)>=0.5){
		benefit+=0.01;
	}
	printf("%.2f",benefit);
	return 0;
}
