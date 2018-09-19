#include<stdio.h>
#include<string.h>
int a[1000000];
int main(){
    int n,m;
    int i,j;
    while(~scanf("%d",&n)){
            memset(a,'\0',sizeof(a));
        if(n==0){
            printf("list is empty\n");
        }
        else{
            for(i=1;i<=n;i++){
                scanf("%d",&a[i]);
                printf("%d ",a[i]);
            }
            printf("\n");
           for(i=1;i<=n;i++){
            if(a[i]!=a[i-1]){
                printf("%d ",a[i]);
             }
           }
           printf("\n");
        }
    }
    return 0;
}

