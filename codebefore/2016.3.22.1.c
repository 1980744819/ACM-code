#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%d%d",&a,&b);
    c=a+b;
    if(c<0)
        c=-c;
    c%=10;
    printf("%d\n",c);
    return 0;
}

