#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	cin>>N; 
	int a[54];
	for(int i=0;i<54;i++){
		cin>>a[i];
	}
	string array[]={"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
	"H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
	"C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
	"D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
	"J1","J2"
	};
	int shufle[54];
	for(int i=0;i<54;i++){
		shufle[i]=i;
	}
	for(int i=0;i<N;i++){
		int tmp[54];
		for(int j=0;j<54;j++){
			tmp[a[j]-1]=shufle[j];
		}
		for(int j=0;j<54;j++){
			shufle[j]=tmp[j];
		}
	}
	for(int i=0;i<54;i++){
		if(i)printf(" ");
		cout<<array[shufle[i]];
	}
	return 0;
}
