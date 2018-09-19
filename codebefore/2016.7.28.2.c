#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int a[100005];
int main(){
    int kase;
    int time=0;
    scanf("%d",&kase);
    while(kase--){
            time++;
            int num;
            scanf("%d",&num);
            int i,j;
            int b;
            for(i=1;i<=num;i++){
                scanf("%d",&b);
                a[b]=b-i;
                if(a[b]<0)
                    a[b]=0-a[b];
            }
            printf("Case #%d:",time);
            for(i=1;i<=num;i++){
                printf(" %d",a[i]);
                a[i]=0;
            }
            printf("\n");
    }
    return 0;
}
