#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
struct node{
    int step;
    int loc;
};
struct node que[1000005];
int book[400005];
int main(){
    int start,end;
    int head=0;
    int tail=0;
    scanf("%d %d",&start,&end);
    if(start>=end)
        printf("%d\n",start-end);
    else{
        que[tail].loc=start;
        que[tail].step=0;
        book[start]=1;
        tail++;
        int i,j;
        int t=0;
        int flag=0;
        while(head<tail){
            for(i=1;i<=3;i++){
                if(i==1){
                    t=que[head].loc-1;
                }
                else if(i==2){
                    t=que[head].loc+1;
                }
                else if(i==3){
                    t=que[head].loc*2;
                }
                if(t<0||t>100005)
                    continue;
                if(book[t]==0){
                    book[t]=1;
                    que[tail].loc=t;
                    que[tail].step=que[head].step+1;
                    tail++;
                }
                if(t==end){
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
            head++;
        }
        printf("%d\n",que[tail-1].step);
    }
    return 0;
}

