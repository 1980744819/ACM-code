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
    int num=0;
    int tmp,tm;
    int a[5];
    int i;
    while(num<32){
        tmp=num;
        for(i=0;i<5;i++){
            tm=tmp%2;
            a[i]=tm;
            tmp>>=1;
        }
        for(i=4;i>=0;i--){
            printf("%d",a[i]);
        }
        printf("\n");
        num++;
    }
    return 0;
}

