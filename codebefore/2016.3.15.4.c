#include<stdio.h>
int main(){
    int a ,b,c,d;
    while(~scanf("%d%d",&a,&b)){
        if(b==0)
            printf("error\n");
        else{
            c=a*10/b;
            d=a/b*10;
            if(c-d>=5)
                printf("%d\n",a/b+1);
            else
                printf("%d\n",a/b);
        }
    }
    return 0;
}
