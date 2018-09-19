#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int book[51];
int map[51][51];
int main(){
    int n;
    int i,j;
    int que[100001];
    int head,tail;
    while(~scanf("%d",&n)){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&map[i][j]);
            }
        }
        head=1;
        tail=1;
        que[tail]=1;
        tail++;
        book[1]=1;
        while(head<tail){
            int cur=que[head];
            for(i=1;i<=n;i++){
                if(map[cur][i]==1&&book[i]==0){
                    que[tail]=i;
                    tail++;
                    book[i]=1;
                }
                if(tail>n)
                    break;
            }
            head++;
        }
        for(i=1;i<tail;i++){
            printf("%d ",que[i]-1);
        }
        printf("\n");
    }
    return 0;
}

