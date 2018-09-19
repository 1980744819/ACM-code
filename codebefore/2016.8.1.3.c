#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int col[10][10];
int row[10][10];
int grid[10][10];
int map[10][10];
int dfs(int x,int y){
    //printf("%d %d\n",x,y);
   if(y==10) {return 1;printf("1\n");}
   int flag=0;
   if(map[x][y]){
        if(x==9)
            flag=dfs(1,y+1);
        else
            flag=dfs(x+1,y);
        //printf("1\n");
        return flag;
    }
   else{
        int t;
        int i;
        t=3*((x-1)/3)+(y-1)/3+1;
        for(i=1;i<=9;i++){
            if(!col[x][i]&&!row[y][i]&&!grid[t][i]){
            map[x][y]=i;
                /*printf("%d %d %d\n",x,y,i);
            int m,n;
            for(m=1;m<=9;m++){
                for(n=1;n<=9;n++){
                    printf("%d",map[m][n]);
                }
                printf("\n");
            }*/
                col[x][i]=1;
                row[y][i]=1;
                grid[t][i]=1;
                if(x==9)
                    flag=dfs(1,y+1);
                else
                    flag=dfs(x+1,y);
                if(!flag){
                    map[x][y]=0;
                    row[y][i]=0;
                    col[x][i]=0;
                    grid[t][i]=0;
                }
                else
                    return 1;
            }
        }
   }
    return 0;
}
int main(){
    int kase;
    scanf("%d",&kase);
    while(kase--){
        int i,j;
        char ch;
        int t;
        for(i=1;i<=9;i++){
            getchar();
            for(j=1;j<=9;j++){
                scanf("%c",&ch);
                map[i][j]=ch-48;
                if(map[i][j]){
                    col[i][map[i][j]]=1;
                    row[j][map[i][j]]=1;
                    t=3*((i-1)/3)+(j-1)/3+1;
                    grid[t][map[i][j]]=1;
                }
            }
        }
        dfs(1,1);
        for(i=1;i<=9;i++){
            for(j=1;j<=9;j++){
                printf("%d",map[i][j]);
            }
            printf("\n");
        }
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(grid,0,sizeof(grid));
    }
    return 0;
}

