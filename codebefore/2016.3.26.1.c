#include<stdio.h>
#include<string.h>

int main(){
    int m,n;
    int i,j,s=0;
    while(~scanf("%d%d",&m,&n)&&n){
        for(i=1;i<=m;i++){
            s=(s+n)%i;
        }
        printf("%d\n",s+1);
    }
    return 0;
}


