#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int top[11];
int time[11];
int qu[11][201];
int m,tol;
float tc=0;
void pu(int a,int b){
    int k;
    int t=cho(a,b);
    //printf("%d\n",t);
    top[t]++;
    qu[t][top[t]]=a+b;
}
int cho(int a,int b){
    int i=0;
    for(i=0;i<m;i++){
        if(time[i]+qu[i][top[i]]<=a){
            time[i]=0;
            return i;
        }
    }
    int min=999999;
    int t=0;
    for(i=0;i<m;i++){
        if((time[i]+qu[i][top[i]]-a)<min){
            min=time[i]+qu[i][top[i]]-a;
            //printf("%d\n",min);
            t=i;
        }
    }
    time[t]=min;
    tc+=min;
    return t;
}
int main(){
    int i,j;
    while(~scanf("%d",&m)){
        scanf("%d",&tol);
        int a,b;
        for(i=0;i<tol;i++){
            scanf("%d %d",&a,&b);
                pu(a,b);
        }
        printf("%1.2f\n",tc/tol);
        memset(time,0,sizeof(time));
        memset(top,0,sizeof(top));
        tc=0;
    }
    return 0;
}

