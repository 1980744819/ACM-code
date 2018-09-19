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
    int num;
    char c[200];
    int lenc;
    int i,j;
    int tm,tmp;
    while(~scanf("%d",&num)){
        lenc=0;
        if(num==0){
            printf("0\n");
            continue;
        }
        while(num){
            tm=num%16;
            if(tm<=9){
                c[lenc]=tm+'0';
            }
            else{
                c[lenc]=tm+'A'-10;
            }
            lenc++;
            num/=16;
        }
        for(i=lenc-1;i>=0;i--){
            printf("%c",c[i]);
        }
        printf("\n");
    }
    return 0;
}

