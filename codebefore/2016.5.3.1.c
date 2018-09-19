#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int s[5][5];
int book[5][5];
int ans=99999;
int next[5][2]={{0,0},{0,1},{1,0},{-1,0},{0,-1}};
int tx,ty;
int step;
int flag=0;
int judge(){
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(s[i][j]!=s[0][0])
                return 0;
    return 1;
}
void flip(int row,int col){
    int k;
    for(k=0;k<5;k++){
        tx=row+next[k][0];
        ty=col+next[k][1];
        if(tx>=0&&tx<4&&ty>=0&&ty<4){
            s[tx][ty]=!s[tx][ty];
        }
    }
    return;
}
void dfs(int row,int col,int deep){
    if(deep==step){
        flag=judge();
        //printf("%d\n",flag);
        return;
    }
    if(flag||row==4) return;
    flip(row,col);
    if(col<3)
        dfs(row,col+1,deep+1);
    else
        dfs(row+1,0,deep+1);
    flip(row,col);
    if(col<3)
        dfs(row,col+1,deep);
    else
        dfs(row+1,0,deep);
    return;
}
int main(){
    int i,j,k;
    char temp;
    /*for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }*/
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            scanf("%c",&temp);
            if(temp=='w')
                s[i][j]=1;
        }
        getchar();
    }
   /* for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }*/
        for(step=0;step<=16;step++){
            dfs(0,0,0);
            if(flag)
                break;
        }
        if(flag)
            printf("%d\n",step);
        else
            printf("Impossible\n");
    return 0;
}
