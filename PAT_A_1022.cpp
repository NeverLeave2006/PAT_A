#include <iostream>
#include <map>
#include <set>
using namespace std;

map<string,set<int> > title,author,keyWords,publisher,year;

void querry(int type,string s){
	set<int> si;
	switch(type){
		case 1:si=title[s];break;
		case 2:si=author[s];break;
		case 3:si=keyWords[s];break;
		case 4:si=publisher[s];break;
		case 5:si=year[s];break;
	}
	if(si.size()!=0){
		for(set<int>::iterator it=si.begin();it!=si.end();it++){
			printf("%07d\n",*it);
		}
	}else{
		printf("Not Found\n");
	}
	
}

int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	for(int i=0;i<N;i++){
		int id;
		scanf("%d",&id);
		getchar();
		string tmp;
		getline(cin,tmp);
		title[tmp].insert(id);
		getline(cin,tmp);
		author[tmp].insert(id);
		string key;
		while(cin>>key){
			keyWords[key].insert(id);
			char c=getchar();
			if(c=='\n')break;
		}
		getline(cin,tmp);
		publisher[tmp].insert(id);
		getline(cin,tmp);
		year[tmp].insert(id);
		
	}
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int type;
		scanf("%d: ",&type);
		string s;
		getline(cin,s);
		cout<<type<<": "<<s<<endl;
		querry(type,s);
	}
	return 0;
 } 
