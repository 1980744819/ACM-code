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
    int num=1000;
    int a[4];
    int tmp;
    while(num<=9999){
        a[0]=num%10;
        a[1]=num%100/10;
        a[2]=num%1000/100;
        a[3]=num%10000/1000;
        tmp=a[0]*1000+a[1]*100+a[2]*10+a[3];
        if(tmp==num)
            printf("%d\n",num);
        num++;
    }
    return 0;
}

