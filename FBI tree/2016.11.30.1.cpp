#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
char s[1030];
void pos(int st,int en){
    if(st==en){
        if(s[st]=='0')
            printf("B");
        else
            printf("I");
        return;
    }
    int flagb=0;
    int flagi=0;
    int i;
    int mid;
    for(i=st;i<=en;i++){
        if(s[i]=='0')
            flagb=1;
        if(s[i]=='1')
            flagi=1;
    }
    mid=st+en;
    mid/=2;
    pos(st,mid);
    pos(mid+1,en);
    if(flagb&&flagi)
        printf("F");
    else if(flagb&&!flagi)
        printf("B");
    else
        printf("I");
}
int main(){
    int i,j,k;
    int kase;
    scanf("%d",&kase);
    int n;
    while(kase--){
        scanf("%d",&n);
        n=pow(2,n);
        getchar();
        for(i=1;i<=n;i++)
            scanf("%c",&s[i]);
        pos(1,n);
        printf("\n");
    }
    return 0;
}
