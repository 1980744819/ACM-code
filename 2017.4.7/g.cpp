#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    char c[10];
    int i,j;
    int lenc;
    long long num;
    int tmp;
    while(~scanf("%s",c)){
        num=0;
        lenc=strlen(c);
        for(i=0;i<lenc;i++){
            if(c[i]>='0'&&c[i]<='9'){
                tmp=c[i]-'0';
            }
            else{
                tmp=c[i]-'A'+10;
            }
            num+=pow(16,lenc-i-1)*tmp;
        }
        printf("%lld\n",num);
    }
    return 0;
}

