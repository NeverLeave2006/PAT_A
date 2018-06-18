#include <iostream>
#include <set>
#include <map>
using namespace std;

struct Node{
  int flag;
  char Data;
  int Next;
};

map<int,Node> m_iN;
set<int> s_i;

int main()
{
  int addr1,addr2,N;
  scanf("%d%d%d",&addr1,&addr2,&N);
  for(int i=0;i<N;i++){
    int a,next;
    char tmp;
    scanf("%d %c %d",&a,&tmp,&next);
    Node tmpN;
    tmpN.flag=false;
    tmpN.Data=tmp;
    tmpN.Next=next;
    m_iN[a]=tmpN;
    getchar();
  }
  int next=addr1;
  while(next!=-1){
    Node t=m_iN[next];
    //printf("%d %c %05d\n",t.flag,t.Data,t.Next);
    t.flag=1;
    m_iN[next]=t;
    next=t.Next;
  }
  next=addr2;
  while(next!=-1){
    Node t=m_iN[next];
    if(t.flag){

      break;
    }
    next=t.Next;
  }
  if(next!=-1){
    printf("%05d\n", next);
  }else{
    printf("%d\n", next);
  }
  return 0;
}
