#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int main(){
    int t;
    int a,b,flag;
    while(scanf("%d",&t)==1&&t){
            flag=0;
        while(t--){
            scanf("%d",&a);
            while(a--){
                scanf("%d",&b);
                if(b==1)
                    flag=1;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

