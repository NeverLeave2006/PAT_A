#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Plus(vector<int> v1,vector<int> v2){
  vector<int> res;
  int tmp=0;
  for(int i=0;i<v1.size();i++){
    res.push_back((v1[i]+v2[i]+tmp)%10);
    tmp=(v1[i]+v2[i]+tmp)/10;
  }
  if(tmp)res.push_back(tmp);
  reverse(res.begin(),res.end());
  return res;
}

void Print(vector<int> v1){
  for(int i=0;i<v1.size();i++){
    printf("%d",v1[i]);
  }
}

bool equal(vector<int> v1,vector<int> v2){
  return v1==v2;
}

int main(){
  string s;
  getline(cin,s);
  vector<int> V_i;
  for(int i=0;i<s.length();i++){
    int tmp=(s[i])-'0';
    V_i.push_back(tmp);
  }
  vector<int> v1=V_i;
  reverse(V_i.begin(),V_i.end());
  vector<int> v2=V_i;
  int cnt=0;
  while(!equal(v1,v2)){
    vector<int> V=Plus(v1,v2);
    Print(v1);
    printf(" + ");
    Print(v2);
    printf(" = ");
    Print(V);
    printf("\n");
    v1=V;
    reverse(V.begin(),V.end());
    v2=V;
    if(cnt>=9)break;
    cnt++;
  }
  if(equal(v1,v2)){
    Print(v2);
    printf(" is a palindromic number.");
  }else{
    printf("Not found in 10 iterations.");
  }
  return 0;
}
