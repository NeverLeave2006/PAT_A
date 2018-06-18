#include <iostream>
#include <queue>
using namespace std;

int M,N,L,T;
struct Node{
	int x,y,z;
};

int pix[62][1290][130];
int inq[62][1290][130]={0};

int X[6]={0,0,1,-1,0,0};
int Y[6]={0,0,0,0,1,-1};
int Z[6]={1,-1,0,0,0,0};

bool Judge(int x,int y,int z){
	if(x<0||y<0||z<0||x>=L||y>=M||z>=N)return false;
	if(!pix[x][y][z]||inq[x][y][z])return false;
	return true;
}

int vol=0;

void BFS(int x,int y,int z){
	Node tmp;
	tmp.x=x;
	tmp.y=y;
	tmp.z=z;
	queue<Node> Q;
	Q.push(tmp);
	int v=0;
	while(!Q.empty()){
		Node t=Q.front();
		int x=t.x,y=t.y,z=t.z;
		inq[x][y][z]=1;//Ç§Íò²»ÄÜÍü£¡£¡£¡£¡£¡£¡ 
		Q.pop();
		v++;
		for(int i=0;i<6;i++){
			if(Judge(x+X[i],y+Y[i],z+Z[i])){
				Node t2;
				t2.x=x+X[i];
				t2.y=y+Y[i];
				t2.z=z+Z[i];
				Q.push(t2);
				inq[x+X[i]][y+Y[i]][z+Z[i]]=1;
				
			}
		}
	}
	if(v>=T){
		vol+=v;
	}
}

int main()
{
	scanf("%d%d%d%d",&M,&N,&L,&T);
	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				scanf("%d",&pix[i][j][k]);
			}
		}
	}
	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				if(!inq[i][j][k]&&pix[i][j][k]){
					BFS(i,j,k);
				}
			}
		}
	}
	printf("%d",vol);
	return 0;
}
