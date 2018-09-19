#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#define up 1
#define right 0
#define wall 2
#define door 1
#define null 0
int map[201][201][2];
int book[201][201];
int head;
int tail;
int m,n;
struct stu{
    int x;
    int y;
    int step;
};
struct stu q[50000];
int inf=9999999;
void bfs(int startx,int starty){
    int next[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
    int flag=0;
    head=0;
    tail=0;
    q[head].x=startx;
    q[head].y=starty;
    q[head].step=0;
    int i,j;
    int tx,ty;
    int k;
    tail++;
    while(head<tail){
        for(k=0;k<4;k++){
            tx=q[head].x+next[k][0];
            ty=q[head].y+next[k][1];
            if(tx<=0||ty<=0||tx>=199||ty>=199){
                continue;
            }
            if(k==0||k==1){
                if(book[tx][ty]==2&&map[tx][ty][right]!=wall){
                    q[tail].x=tx;
                    q[tail].y=ty;
                    book[tx][ty]=1;
                    q[tail].step=q[head].step+1;
                    printf("%d %d %d\n",q[tail].x,q[tail].y,q[tail].step);
                    tail++;
                }
            }
            else {
                if(book[tx][ty]==2&&map[tx][ty][up]!=wall){
                    q[tail].x=tx;
                    q[tail].y=ty;
                    book[tx][ty]=1;
                    q[tail].step=q[head].step+1;
                    printf("%d %d %d\n",q[tail].x,q[tail].y,q[tail].step);
                    tail++;
                }
            }
        }
        head++;
    }
}
int main(){
    int i,j;
    int x,y,d,t;
    int len;
    double endx,endy;
    while(~scanf("%d %d",&m,&n)){
        if(n==-1&&m==-1)
            break;
        for(i=0;i<m;i++){
            scanf("%d%d%d%d",&x,&y,&d,&t);
            if(d){
                for(j=0;j<d;j++)
                    map[x-1][y+j][up]=wall;
                    book[x-1][y+j]=2;
            }
            else{
                for(j=0;j<d;j++)
                    map[x+j][y-1][right]=wall;
                    book[x+j][y-1]=2;
            }
        }
        for(i=0;i<n;i++){
            scanf("%d%d%d",&x,&y,&d);
            if(d)
                map[x-1][y][up]=door;
            else
                map[x][y-1][right]=door;
        }
        int startx,starty;
        scanf("%lf %lf",&endx,&endy);
        startx=(int )(endx+0.0001);
        starty=(int )(endy+0.0001);
        book[startx][starty]=1;
        //printf("%d %d\n",startx,starty);
        //printf("%lf %lf\n",endx,endy);
        if(m==0&&n==0){
            printf("0\n");
            continue;
        }
        if(startx<=0||starty<=0||startx>=199||starty>=199)
            printf("0\n");
        else{
            bfs(startx,starty);
            if(q[tail].step<inf){
                printf("%d\n",q[tail].step);
            }
            else
                printf("-1\n");
        }
        printf("%d\n",q[tail-1].step);
    }
    return 0;
}
