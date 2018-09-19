#include<stdio.h>
#include<string.h>
int a[1000000];
int main(){
    int n;
    int i,j;
    while(~scanf("%d",&n)){
        if(n==0){
            printf("list is empty\n");
        }
        else{
            for(i=0;i<n;i++){
                scanf("%d",&a[i]);
            }
            for(i=0;i<n;i++){
                printf("%d ",a[i]);
            }
            printf("\n");
            for(i=n-1;i>=0;i--){
                printf("%d ",a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
