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
int main(){
    int m,n;
    int na,nb;
    int ma,mb;
    int a;
    int sa,sb;
    while(~scanf("%d %d",&m,&n)){
        na=0;nb=0;
        ma=0;mb=0;
        sa=0;sb=0;
        while(m--){
            scanf("%d",&a);
            if(a){
                na++;
                sa+=a;
            }
            if(a>ma)
                ma=a;
        }
        while(n--){
            scanf("%d",&a);
            if(a){
                nb++;
                sb+=a;
            }
            if(a>mb)
                mb=a;
        }
        if(sa!=sb||ma>nb||mb>na)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}

