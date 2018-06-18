#include <iostream>
using namespace std;

struct inf{
	string name;
	string sex;
	string id;
	int grade;
};

inf ML,FH;

int main()
{
	ML.grade=101;
	FH.grade=-1;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		inf tmp;
		cin>>tmp.name>>tmp.sex>>tmp.id>>tmp.grade;
		if(tmp.sex=="M"){
			if(ML.grade>tmp.grade)
				ML=tmp;
		}
		if(tmp.sex=="F"){
			if(FH.grade<tmp.grade)
				FH=tmp;
		}
	}
	if(FH.grade==-1)printf("Absent\n");
	else cout<<FH.name<<" "<<FH.id<<endl;
	if(ML.grade==101)printf("Absent\n");
	else cout<<ML.name<<" "<<ML.id<<endl;
	if(ML.grade!=101&&FH.grade!=-1)printf("%d\n",FH.grade-ML.grade);
	else  printf("NA\n");
	return 0;	
} 
