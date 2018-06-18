#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct info{
	string registration_number;
	int final_rank;
	int location_number;
	int local_rank;
	int score;
}; 

bool cmp(info &a,info &b){
	if(a.score!=b.score){
		return a.score>b.score;
	}else{
		return a.registration_number<b.registration_number;
	}
}

int main()
{
	int N,sum=0;;
	scanf("%d",&N);
	vector<vector<info> > s;
	for(int i=1;i<=N;i++){
		int K;
		scanf("%d",&K);
		sum+=K;
		vector<info> v;
		for(int j=0;j<K;j++){
			info tmp;
			cin>>tmp.registration_number;
			cin>>tmp.score;
			tmp.location_number=i;
			v.push_back(tmp);
		}
		sort(v.begin(),v.end(),cmp);
		for(int j=0;j<K;j++){
			v[j].local_rank=j+1;
			if(v[j].score==v[j-1].score&&j!=0){
				v[j].local_rank=v[j-1].local_rank;
			}
		}
		s.push_back(v);
	}
	printf("%d\n",sum);
	vector<info> infoSum;
	vector<vector<info> >::iterator it=s.begin();
	while(it!=s.end()){
		infoSum.insert(infoSum.end(),it->begin(),it->end());
		it++;
	}
	sort(infoSum.begin(),infoSum.end(),cmp);
	for(int i=0;i<infoSum.size();i++){
		infoSum[i].final_rank=i+1;
		if(infoSum[i].score==infoSum[i-1].score&&i!=0){
			infoSum[i].final_rank=infoSum[i-1].final_rank;
		}
	}
	vector<info>::iterator it2=infoSum.begin();
	while(it2!=infoSum.end()){
		cout<<it2->registration_number<<" "<<it2->final_rank<<" "<<it2->location_number<<" "<<it2->local_rank<<endl;
		it2++;
	}
	return 0;
}
