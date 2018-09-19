#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<malloc.h>
#include<math.h>
char map[21][21];
int startx,starty,endx,endy;
int m,n;
int nextx[4]={-1,1,0,0};
int nexty[4]={0,0,-1,1};
int min;
int pan(int i,int x,int y){
    int flag1=0;
    int flag2=0;
    //printf("%d\n",i);
    switch(i){
        case 0:{
            //printf("0\n");
            while(x--){
                if(map[x][y]==3){flag2=2;break;}
                else if(map[x][y]==1){flag1=1;break;}
            }
            break;
        }
        case 1:{
            //printf("1\n");
            while(x++){
                if(x>n)break;
                if(map[x][y]==3){flag2=2;break;}
                else if(map[x][y]==1){flag1=1;break;}
            }
            break;
        }
        case 2:{
            //printf("2\n");
            while(y--){
                if(map[x][y]==3){flag2=2;break;}
                else if(map[x][y]==1){flag1=1;break;}
            }
            break;
        }
        case 3:{
            //printf("3\n");
            while(y++){
                if(y>m)break;
                if(map[x][y]==3){flag2=2;break;}
                else if(map[x][y]==1){flag1=1;break;}
            }
            break;
        }
        default:break;
    }
    if(flag2==2)
        return 2;
    if(flag1==1)
        return 1;
    return 0;
}
void dfs(int i,int j,int step){
    //printf("%d ",step);
    int x=i,y=j;
    int k;
    if(step>10)
        return ;
    for(k=0;k<4;k++){
        x=i+nextx[k];
        y=j+nexty[k];
        if(map[x][y]==3){
            if(min>step)
                min=step;
                //step--;
                //printf("%d\n",min);
            return;
        }
        if(map[x][y]!=1&&x>=0&&x<n&&y>=0&&y<m){
            int p=pan(k,x,y);
            if(p==1){
                //printf("%d %d\n",x,y);
                while(map[x][y]!=1){
                    x+=nextx[k];
                    y+=nexty[k];
                    if(map[x][y]==3){
                        if(min>step)
                            min=step;
                        //printf("%d\n",min);
                        //step--;
                        return;
                    }
                }
                int xx=x,yy=y;
                map[x][y]=0;
                x-=nextx[k];
                y-=nexty[k];
                //printf("%d %d\n",x,y);
                dfs(x,y,step+1);
                map[xx][yy]=1;
                //step--;
            }
            else if(p==2){
                if(min>step)
                    min=step;
                    //step--;
                return;
            }
        }
    }
}
int main(){
    int i,j;
    while(~scanf("%d%d",&m,&n)){
        if(m==0&&n==0)
            break;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j]==2){startx=i;starty=j;map[i][j]=0;}
                if(map[i][j]==3){endx=i,endy=j;}
            }
        }
        min=9999999;
        dfs(startx,starty,1);
        if(min<=10)
            printf("%d\n",min);
        else
            printf("-1\n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                map[i][j]='\0';
            }
        }
       /* for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("%d",map[i][j]);
            }
            printf("\n");
        }*/
    }
    return 0;
}
