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
    int num=100;
    int a,b,c;
    int tmp;
    while(num<=999){
        a=num%10;
        b=num%100/10;
        c=num%1000/100;
        tmp=a*a*a+b*b*b+c*c*c;
        if(tmp==num)
        printf("%d\n",num);
        num++;
    }
    return 0;
}

