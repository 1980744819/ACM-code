#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<malloc.h>
#include<cmath>
using namespace std;
long long ans,lastline;
void coun(long long row,long long ld,long long rd){
    if(row!=lastline){
        long long position=lastline & ~(row|ld|rd);
        while(position){
            long long p;
            p=position & (~position+1);
            position=position -p;
            coun(row|p,(ld|p)<<1,(rd|p)>>1);
        }
    }
    else{
        ans++;
    }
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n!=0){
        lastline=(1<<n)-1;
        ans=0;
        coun(0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
