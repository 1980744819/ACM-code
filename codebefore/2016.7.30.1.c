#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char operation[6][10]={"FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};
struct queue{
    int a;
    int b;
    int fa;
    int step;
    char op[10];
}q[1000000];
int v[105][105];
int main(){
    int num1,num2,c;
    while(~scanf("%d%d%d",&num1,&num2,&c)){
        int head,tail;
        head=0;
        tail=0;
        q[head].a=0;
        q[head].b=0;
        q[head].fa=-1;
        q[head].step=0;
        q[head].op[0]='\0';
        v[q[head].a][q[head].b]=1;
        tail++;
        int flag;
        int i,j;
        flag=0;
        while(head<tail){
            //printf("1\n");
            if(q[head].a!=num1&&v[num1][q[head].b]==0){
                v[num1][q[head].b]=1;
                q[tail].a=num1;
                q[tail].b=q[head].b;
                q[tail].fa=head;
                q[tail].step=q[head].step+1;
                strcpy(q[tail].op,operation[0]);
                tail++;
                if(q[tail-1].a==c||q[tail-1].b==c){
                    flag=1;
                    break;
                }
            }
            if(q[head].b!=num2&&v[q[head].a][num2]==0){
                v[q[head].a][num2]=1;
                q[tail].b=num2;
                q[tail].a=q[head].a;
                q[tail].fa=head;
                q[tail].step=q[head].step+1;
                strcpy(q[tail].op,operation[1]);
                tail++;
                if(q[tail-1].a==c||q[tail-1].b==c){
                    flag=1;
                    break;
                }
            }
            if(q[head].a!=0&&v[0][q[head].b]==0){
                v[0][q[head].b]=1;
                q[tail].a=0;
                q[tail].b=q[head].b;
                q[tail].fa=head;
                q[tail].step=q[head].step+1;
                strcpy(q[tail].op,operation[2]);
                tail++;
                if(q[tail-1].a==c||q[tail-1].b==c){
                    flag=1;
                    break;
                }
            }
            if(q[head].b!=0&&v[q[head].a][0]==0){
                v[q[head].a][0]=1;
                q[tail].b=0;
                q[tail].a=q[head].a;
                q[tail].fa=head;
                q[tail].step=q[head].step+1;
                strcpy(q[tail].op,operation[3]);
                tail++;
                if(q[tail-1].a==c||q[tail-1].b==c){
                flag=1;
                    break;
                }
            }
            if(q[head].a!=0){
                int t1=q[head].a;
                int t2=q[head].b;
                while(t1!=0&&t2<num2){
                    t1--;
                    t2++;
                }
                if(v[t1][t2]==0){
                    v[t1][t2]=1;
                    q[tail].a=t1;
                    q[tail].b=t2;
                    q[tail].fa=head;
                    q[tail].step=q[head].step+1;
                    strcpy(q[tail].op,operation[4]);
                    tail++;
                    if(q[tail-1].a==c||q[tail-1].b==c){
                        flag=1;
                        break;
                    }
                }
            }
            if(q[head].b!=0){
                int t1=q[head].a;
                int t2=q[head].b;
                while(t2!=0&&t1<num1){
                    t2--;
                    t1++;
                }
                if(v[t1][t2]==0){
                    v[t1][t2]=1;
                    q[tail].a=t1;
                    q[tail].b=t2;
                    q[tail].fa=head;
                    q[tail].step=q[head].step+1;
                    strcpy(q[tail].op,operation[5]);
                    tail++;
                    if(q[tail-1].a==c||q[tail-1].b==c){
                        flag=1;
                        break;
                    }
                }
            }
            head++;
            //printf("%d %d\n",head,tail);
        }
        int move[100000];
        if(flag){
            printf("%d\n",q[tail-1].step);
            int t=0;
            //move[0]=q[tail].fa;
            int p=tail-1;
            for(t=0;t<q[tail-1].step;t++){
                    move[t]=p;
                    //printf("%d %d\n",p,t);
                    //t++;
                    p=q[p].fa;
            }
            for(t=t-1;t>=0;t--){
                //t--;
                printf("%s\n",q[move[t]].op);
                //t--;
            }
            //printf("%s\n",q[move[t]].op);
        }
        else printf("impossible\n");
        for(i=0;i<101;i++){
            for(j=0;j<101;j++){
                v[i][j]=0;
            }
        }
    }
    return 0;
}
