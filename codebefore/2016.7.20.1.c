#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<malloc.h>
#include<math.h>
int map[12][12];
char direc[12][12];
int m,n;
void move(int start){
    int sum;
    map[0][start]=1;
    sum=1;
    int x=0,y=start;
    int flag=1;
    while(flag){
            switch(){
                case 'N':{
                    x--;
                    if(x<0){
                        flag=0;
                        printf("%d step(s) to exit\n",sum);
                    }
                    else if(map[x][y]!=0){
                        flag=0;
                        printf("%d step(s) before a loop of %d step(s)\n",map[x][y]-1,sum-map[x][y]+1);
                    }
                    else{
                        sum++;
                        map[x][y]=sum;
                    }
                    break;
                }
                case 'S':{
                    x++;
                    if(x>m){
                        flag=0;
                        printf("%d step(s) to exit\n",sum);
                    }
                    else if(map[x][y]!=0){
                        flag=0;
                        printf("%d step(s) before a loop of %d step(s)\n",map[x][y]-1,sum-map[x][y]+1);
                    }
                    else{
                        sum++;
                        map[x][y]=sum;
                    }
                    break;
                }
                case 'E':{
                    y++;
                    if(y>n){
                        flag=0;
                        printf("%d step(s) to exit\n",sum);
                    }
                    else if(map[x][y]!=0){
                        flag=0;
                        printf("%d step(s) before a loop of %d step(s)\n",map[x][y]-1,sum-map[x][y]+1);
                    }
                    else{
                        sum++;
                        map[x][y]=sum;
                    }
                    break;
                }
                case 'W':{
                    y--;
                    if(y<0){
                        flag=0;
                        printf("%d step(s) to exit\n",sum);
                    }
                    else if(map[x][y]!=0){
                        flag=0;
                        printf("%d step(s) before a loop of %d step(s)\n",map[x][y]-1,sum-map[x][y]+1);
                    }
                    else{
                        sum++;
                        map[x][y]=sum;
                    }
                    break;
                }
            }
            if(!flag)
                break;
    }
}

int main(){
    int i,j;
    int start;
    while(~scanf("%d%d%d",&m,&n,&start)){
        if(m==0&&n==0&&start==0)
            break;
        for(i=0;i<m;i++){
                scanf("%s",direc[i]);
        }
        move(start-1);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                map[i][j]=0;
                direc[i][j]=0;
            }
        }
    }
    return 0;
}
