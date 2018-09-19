#include<stdio.h>
#include<string.h>
int main(){
    int a1,a2,b1,b2;
    while(~scanf("%d %d %d %d",&a1,&a2,&b1,&b2)){
        if(a1==a2&&b1==b2){
            if(a1==b1)
                printf("N\n");
            else if(a1>b1)
                printf("A\n");
            else printf("B\n");
        }
        else if(b1==b2&&a1!=a2){
            printf("B\n");
        }
        else if(a1==a2&&b1!=b2)
            printf("A\n");
        else if(a1!=a2&&b1!=b2){
            int m=(a1+a2)%10;
            int n=(b1+b2)%10;
            if(m>n) printf("A\n");
            else if(n>m) printf("B\n");
            else printf("N\n");
        }
        else printf("N\n");
    }
    return 0;
}

