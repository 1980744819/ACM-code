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
    int t1,t2,t3;
    t1=1;
    t2=0;
    t3=1;
    for(int i=1;i<=10;i++){
        t3+=t2;
        t2=t1;
        t1=pow(2,i-1);
    }
    printf("%d\n",t1+t2+t3);
    return 0;
}

