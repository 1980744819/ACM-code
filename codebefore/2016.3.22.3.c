#include<stdio.h>
#include<string.h>
int main(){
    int a1,b1,c1,a2,b2,c2;
    char a,b;
    scanf("%d%c%d%c%d",&a1,&a,&b1,&b,&c1);
    scanf("%d%c%d%c%d",&a2,&a,&b2,&b,&c2);
    int t1,t2,t;
    t1=a1*3600+b1*60+c1;
    t2=a2*3600+b2*60+c2;
    t=t2-t1;
    a1=t/3600;
    if(a1<10)
        printf("0");
    printf("%d",a1);
    printf(":");
    b1=t%3600/60;
    if(b1<10)
        printf("0");
    printf("%d",b1);
    printf(":");
    c1=t-a1*3600-b1*60;
    if(c1<10)
        printf("0");
    printf("%d\n",c1);
}
