#include <iostream>
#include <string>
using namespace std;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    string s=to_string(a+b);
    for(int i=0;i<s.length();i++){
        printf("%c",s[i]);
        if(s[i]!='-'&&((s.length()-i-1)!=0&&(s.length()-i-1)%3==0))
            printf(",");
    }
    return 0;
    
}