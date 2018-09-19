#include<stdio.h>
#include<string.h>

int main(){
    int m,n;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        if(m==3||m==4||m==6||n==3||n==4||n==6){
            printf("Yes\n");
        }
        else if(m==5&&n==10){
            printf("Yes\n");
        }
        else if(m==10&&n==5){
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
    return 0;
}

