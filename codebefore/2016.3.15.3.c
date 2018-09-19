#include<stdio.h>
int main(){
    int a,b,t;
   while(~scanf("%d%d",&a,&b)){
        t=(a+b)/2;
        if(a>=11&&b<=a-2||b>=11&&a<=b-2)
            printf("Game Over\n");
        else if(t%2==0)
            printf("A\n");
        else
            printf("B\n");
    }
    return 0;
}
