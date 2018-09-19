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
    int x,y;
    int a[4];
    int i,j;
    int coun;
    int tmp;
    while(~scanf("%d %d",&x,&y)){
        for(i=0;i<3;i++){
            a[i]=y;
        }
        coun=0;
        while(a[2]<x){
            a[2]=a[0]+a[1]-1;
            tmp=a[2];
            a[2]=a[0];
            a[0]=a[1];
            a[1]=tmp;
            coun++;
            /*for(i=0;i<3;i++){
                printf("%d ",a[i]);
            }
            printf("\n");*/
        }
        printf("%d\n",coun);
    }
    return 0;
}

