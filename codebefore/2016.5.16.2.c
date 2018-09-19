#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#define maxn 210
#define up 0
#define down 1
#define left 2
#define right 3
#define air 0
#define wall 1
#define door 2
 int v[211][211];
 int roun[211][211][4];
 int wallnum,doornum,startx,starty;
 double startx1,starty1;
 int next[4][2]={{0,1},{0,-1},{-1,0},{1,0}};//…œœ¬◊Û”“
struct elem{
    int x,y,dir,stepnum;
 }elem;
 typedef struct qu{
    struct elem que[100005];
    int head;
    int tail;
 }qu;
 int changedir(int orignal){
     int newdir;
    if(orignal==up) newdir=down;
    else if(orignal==down) newdir=up;
    else if(orignal==left) newdir=right;
    else newdir=left;
    return newdir;
 }
 void bfs(){
     if(startx==0&&starty==0){printf("0\n");return;}
     struct elem curelem,newelem;
    qu q;
    q.head=0;
    q.tail=0;
    q.que[q.tail].x=startx;
    q.que[q.tail].y=starty;
    q.que[q.tail].dir=-1;
    q.tail++;
    v[startx][starty]=0;
    int minsteps=99999999;
    int k;
    int curx,cury,cursteps,curdir,newx,newy,newdir,newsteps;
    while(!q.tail){
        curelem=q.que[q.head];
        q.tail--;
        curx=curelem.x;cury=curelem.y;curdir=curelem.dir;cursteps=curelem.stepnum;
        if(curx==0&&cury==0){
            if(cursteps<minsteps)
                minsteps=cursteps;
                continue;
        }
        for(k=0;k<4;k++){
            if(k!=curdir){
                if(roun[curx][cury][k]!=wall){
                    newx=curx+next[k][0];
                    newy=cury+next[k][1];
                    if(newx>=0&&newx<=199&&newy>=0&&newy<=199){
                        newdir=changedir(k);
                        if(roun[curx][cury][k]==door)
                            newsteps=cursteps+1;
                        else
                            newsteps=cursteps;
                        if(v[newx][newy]==0xbf||newsteps<v[newx][newy]&&newsteps<minsteps){
                            v[newx][newy]=newsteps;
                            newelem.x=newx;newelem.y=newy;newelem.stepnum=newsteps;newelem.dir=newdir;
                            q.que[q.tail]=newelem;
                            q.tail++;
                        }
                    }
                }
            }
        }
    }
    if(minsteps!=99999999)
    printf("%d\n",minsteps);
    else printf("-1\n");
}
int main(){
    while(~scanf("%d%d",&wallnum,&doornum)){
        if(wallnum==-1&&doornum==-1) break;
        int i,j;
        int x,y,d,t;
        for(i=1;i<=wallnum;i++){
            scanf("%d%d%d%d",&x,&y,&d,&t);
            if(d){
                for(j=y;j<=y+t;j++){
                    roun[x][j][left]=roun[x+1][j][right]=wall;
                }
            }
            else{
                for(j=x;j<=x+t;j++){
                    roun[j][y][down]=roun[j][y-1][up]=wall;
                }
            }
        }
        for(i=1;i<=doornum;i++){
            scanf("%d%d%d",&x,&y,&d);
            if(d){
                roun[x][y][left]=roun[x+1][y][right]=door;
            }
            else{
                roun[x][y][down]=roun[x][y-1][up]=door;
            }
        }
        scanf("%lf %lf",&startx1,&starty1);
        startx=(int)startx1;
        starty=(int)starty1;
        //printf("%d %d\n",startx,starty);
        if(wallnum==0&&doornum==0)printf("0\n");
        else if(startx1<0||startx1>199||starty1<0||starty1>199) printf("0\n");
        else
            bfs();
        memset(roun,'0',sizeof(roun));
        memset(v,'0',sizeof(v));
    }
    return 0;
}

