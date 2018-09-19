#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int a[100001];
int top;
int nu[100001];
int head;
int main(){
    int num;
    int i;
    while(~scanf("%d",&num)){
            top=-1;
            head=1;
            a[0]=0;
        for(i=0;i<num;i++){
            scanf("%d",&nu[i]);
        }
        for(i=0;i<num;i++){
                int t=nu[i];
                top++;
                while(a[top-1]<t){
                    a[top]=head;
                    head++;
                    top++;
                    printf("P");
                }
                top--;
                if(a[top]==t){
                    printf("Q");
                    top--;
                }
                else if(a[top]>t){
                    printf(" error");
                    break;
                }
        }
        memset(a,0,sizeof(a));
        memset(nu,0,sizeof(nu));
        printf("\n");
    }
    return 0;
}

