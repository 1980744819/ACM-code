#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#define left 0
#define up 1
#define right 2
#define down 3
char map[41][41];
int sum;
int x;
int y;
int m,n;
int left_change(int x){
    switch(x){
        case left :return down;
        case down :return right;
        case right :return up;
        case up :return left;
    }
}
int right_change(int x){
    switch(x){
        case left :return up;
        case up:return right;
        case right:return down;
        case down:return left;
    }
}
int back_change(int x){
    switch(x){
        case left :return right;
        case up:return down;
        case right:return left;
        case down:return up;
    }
}
int check(int direction){
    switch(direction){
        case left:{
            if(map[x][y-1]!='#'&&y-1>=0)
                return 1;
            else
                return 0;
        }
        case down:{
            if(map[x+1][y]!='#'&&x+1<n)
                return 1;
            else
                return 0;
        }
        case right:{
            if(map[x][y+1]!='#'&&y+1<m)
                return 1;
            else
                return 0;
        }
        case up:{
            if(map[x-1][y]!='#'&&x-1>=n)
                return 1;
            else
                return 0;
        }
    }
}
void move(int dir){
    switch(dir){
        case left:{
            sum++;
            y--;
        }
        case down:{
            sum++;
            x++;
        }
        case right:{
            sum++;
            y++;
        }
        case up:{
            sum++;
            x--;
        }
    }
}
int a[4]={0,1,0,-1};
int b[4]={-1,0,1,0};
int main(){
    int kase;
    scanf("%d",&kase);
    int i,j;
    int startx,starty,endx,endy;
    int direction;
    while(kase--){
        scanf("%d %d",&m,&n);
        for(i=0;i<n;i++){
            getchar();
            for(j=0;j<m;j++){
                scanf("%c",&map[i][j]);
                if(map[i][j]=='S'){startx=i;starty=j;}
                else if(map[i][j]=='E'){endx=i;endy=j;}
            }
        }
        map[endx][endy]='.';
        map[startx][starty]='.';
        direction=left;
        //printf("%d\n",direction);
        sum=0;
        x=startx;
        y=starty;
        int dir;
        while(x!=endx||y!=endy){
                dir=left_change(direction);
                if(check(dir)){//left
                    direction=dir;
                    move(dir);
                    printf("%d ",dir);
                }
                else{
                    if(check(direction)){//stright
                        move(direction);
                        printf("%d ",direction);
                    }
                    else{
                        dir=right_change(direction);
                        if(check(dir)){//right
                            direction=dir;
                            move(dir);
                            printf("%d ",dir);
                        }
                        else{//back
                            direction=back_change(direction);
                            move(direction);
                            printf("%d ",direction);
                        }
                    }
                }
        }
        printf("%d ",sum);
        /*for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%c",map[i][j]);
            }
            printf("\n");
        }*/
    }
    return 0;
}
