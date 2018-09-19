#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int d[2000010];
int main(){
    int t;
    scanf("%d",&t);
    int x[100005];
    int y[100005];
    while(t--){
        int n,m,i,j;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d%d",&x[i],&y[i]);
        }
        if(n>1000){
            printf("YES\n");
            continue;
        }
        int a,b;
        int flag=0;
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                a=x[i]-x[j];
                if(a<0)
                    a=0-a;
                b=y[i]-y[j];
                if(b<0)
                    b=0-b;
                if(d[a+b]==0)
                    d[a+b]=1;
                else{
                    flag=1;
                    printf("YES\n");
                    break;
                }
            }
            if(flag)
                break;
        }
        if(!flag)
            printf("NO\n");
        for(i=0;i<2000010;i++)
            d[i]=0;
    }
    return 0;
}
