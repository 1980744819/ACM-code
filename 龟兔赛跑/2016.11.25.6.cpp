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
    int v1,v2,t,s,l;
    int a1,a2;
    int coun;
    while(~scanf("%d %d %d %d %d",&v1,&v2,&t,&s,&l)){
        a1=0;
        a2=0;
        coun=0;
        while(a1<l&&a2<l){
            a1+=v1;
            a2+=v2;
            coun++;
            if(a1==l||a2==l)
                break;
            if(a1-a2>=t){
                a1-=v1*s;
                //coun+=s;
            }
        }
        if(a1==a2){
            printf("D\n");
        }
        else if(a1>a2)
            printf("R\n");
        else
            printf("T\n");
        printf("%d\n",coun);
    }
    return 0;
}

