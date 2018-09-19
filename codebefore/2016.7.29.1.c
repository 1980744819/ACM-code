#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<malloc.h>
#include<math.h>
struct queue{
    int num;
    int step;
}q[10000000];
int prime[10050];
void init(){
    int i,j;
    int p;
    int flag=0;
    for(i=1000;i<10000;i++){
            flag=0;
        for(j=2;j*j<=i;j++){
            if(i%j==0){prime[i]=0;flag=1;break;}
        }
        if(!flag)
            prime[i]=1;
    }
}
int book[10000];
int main(){
    init();
    int kase;
    scanf("%d",&kase);
    while(kase--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==b){
            printf("0\n");
            continue;
        }
        int head;
        int tail;
        head=0;
        tail=0;
        q[head].num=a;
        q[head].step=0;
        book[a]=1;
        tail++;
        int i,j;
        int t[4];
        int temp;
        int flag;
        flag=0;
        while(head<tail){
            t[0]=q[head].num/1000;
            t[1]=q[head].num%1000/100;
            t[2]=q[head].num%100/10;
            t[3]=q[head].num%10;
            for(i=1;i<10;i+=2){//个位
                if(i==t[3])
                    continue;
                temp=t[0]*1000+t[1]*100+t[2]*10+i;
                if(prime[temp]&&book[temp]==0){
                    book[temp]=1;
                    q[tail].num=temp;
                    q[tail].step=q[head].step+1;
                    tail++;
                    //printf("%d %d\n",q[tail].step,q[tail].num);
                    if(q[tail-1].num==b){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
            for(i=0;i<10;i++){//十位
                if(i==t[2])
                    continue;
                temp=t[0]*1000+t[1]*100+i*10+t[3];
                if(prime[temp]&&book[temp]==0){
                    book[temp]=1;
                    q[tail].num=temp;
                    q[tail].step=q[head].step+1;
                    tail++;
                    //printf("%d %d\n",q[tail].step,q[tail].num);
                    if(q[tail-1].num==b){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
            for(i=0;i<10;i++){//百位
                if(i==t[1])
                    continue;
                temp=t[0]*1000+i*100+t[2]*10+t[3];
                if(prime[temp]&&book[temp]==0){
                    book[temp]=1;
                    q[tail].num=temp;
                    q[tail].step=q[head].step+1;
                    tail++;
                    //printf("%d %d\n",q[tail].step,q[tail].num);
                    if(q[tail-1].num==b){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
            for(i=1;i<10;i++){//千位
                if(i==t[0])
                    continue;
                temp=i*1000+t[1]*100+t[2]*10+t[3];
                if(prime[temp]&&book[temp]==0){
                    book[temp]=1;
                    q[tail].num=temp;
                    q[tail].step=q[head].step+1;
                    tail++;
                    //printf("%d %d\n",q[tail].step,q[tail].num);
                    if(q[tail-1].num==b){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
            head++;
        }
        if(flag){
            printf("%d\n",q[tail-1].step);
        }
        else{
            printf("Impossible\n");
        }
        for(i=1000;i<10000;i++){
            book[i]=0;
        }
    }
    return 0;
}
