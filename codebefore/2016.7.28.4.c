#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<malloc.h>
#include<math.h>
char map[31][31][31];
char book[31][31][31];
struct queue{
    int x;
    int y;
    int z;
    int step;
}q[1000000];
int l,r,c;
int nextx[6]={-1,1,0,0,0,0};
int nexty[6]={0,0,-1,1,0,0};
int nextz[6]={0,0,0,0,-1,1};
int main(){
    while(~scanf("%d%d%d",&l,&r,&c)){
        if(l==0&&r==0&&c==0)
            break;
        int i,j,k;
        int head,tail;
        int startx,starty,startz,endx,endy,endz;
        for(i=0;i<l;i++){
            for(j=0;j<r;j++){
                scanf("%s",map[i][j]);
                for(k=0;k<c;k++){
                    book[i][j][k]=0;
                    if(map[i][j][k]=='S'){
                        startx=j;starty=k;startz=i;
                        map[i][j][k]='.';
                    }
                    else if(map[i][j][k]=='E'){
                        endx=j;endy=k;endz=i;
                        map[i][j][k]='.';
                    }
                }
            }
            getchar();
        }
        /*for(i=0;i<l;i++){
            for(j=0;j<r;j++){
                puts(map[i][j]);
            }
            //getchar();
        }*/
        head=0;tail=0;
        q[head].x=startx;
        q[head].y=starty;
        q[head].z=startz;
        q[head].step=0;
        tail++;
        book[startz][startx][starty]=1;
        int xx,yy,zz;
        int flag;
        flag=0;
        while(head<tail){
            for(i=0;i<6;i++){
                xx=q[head].x+nextx[i];
                yy=q[head].y+nexty[i];
                zz=q[head].z+nextz[i];
                if(xx<0||xx>=r||yy<0||yy>=c||zz<0||zz>=l)
                    continue;
                if(book[zz][xx][yy]==1)
                    continue;
                if(map[zz][xx][yy]=='.'){
                    book[zz][xx][yy]=1;
                    q[tail].x=xx;
                    q[tail].y=yy;
                    q[tail].z=zz;
                    q[tail].step=q[head].step+1;
                    if(q[tail].x==endx&&q[tail].y==endy&&q[tail].z==endz){
                        flag=1;
                        break;
                    }
                    //printf("%d %d %d %d\n",q[tail].step,q[tail].x,q[tail].y,q[tail].z);
                    tail++;
                }
            }
            if(flag)
                break;
            head++;
        }
        if(flag)
            printf("Escaped in %d minute(s).\n",q[head].step+1);
        else
            printf("Trapped!\n");
        for(i=0;i<l;i++){
            for(j=0;j<r;j++){
                for(k=0;k<c;k++){
                    book[i][j][k]=0;
                    map[i][j][k]='\0';
                }
            }
        }
    }
    return 0;
}
