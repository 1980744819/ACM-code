#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
struct queue{
    int num;
    int step;
}q[100000];
int book[10000];
int prime[10000];
void init(){
    int i,j;
    for(i=1000;i<10000;i++){
        for(j=2;j*j<=i;j++){
            if(i%j==0){flag=1;break;}
        }
        if(!flag)prime[i]=1;
    }
}
int main(){
    init();
    int kase;
    scanf("%d",&kase);
    while(kase--){
        int i,j;
        int a,b;
        scanf("%d%d",&a,&b);
        int head,tail;
        head=0;
        tail=0;
        q[head].num=a;
        q[head].step=0;
        book[a]=1;
        int t[4],temp,flag;
        flag=0;
        while(head<tail){
            if(q[head].num==b){
                flag=1;
                printf("%d\n",q[head].step);
                break;
            }
            t[0]=q[head].num/1000;
            t[1]=q[head].num%1000/100;
            t[3]=q[head].num%10;
            for(i=1;i<10;i+=2){
                if(i==t[0])
            }
        }
    }
    return 0;
}
