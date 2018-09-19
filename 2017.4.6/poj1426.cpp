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
bool t;
void dfs(unsigned __int64 m,int num,int k){
    if(t)
        return;
    if(m%num==0){
        t=1;
        printf("%I64u\n",m);
        return;
    }
    if(k==19)
        return;
    dfs(m*10,num,k+1);
    dfs(m*10+1,num,k+1);
}
int main(){
    int num;
    unsigned long long m,tmp;
    while(~scanf("%d",&num)&&num){
        t=0;
        dfs(1,num,0);
    }
    return 0;
}

