#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int p,q;
int chess[9][9];
int nextx[8]={-1,1,-2,2,-2,2,-1,1};
int nexty[8]={-2,-2,-1,-1,1,1,2,2};
char s[100];
int count;
int flag;
void dfs(int startx,int starty,int step){
    //chess[startx][starty]=1;
    //puts(s);
    if(flag)
        return;
    if(step==count){
        puts(s);
        printf("\n");
        flag=1;
        return;
    }
    int i,j;
    int x,y;
    for(i=0;i<8;i++){
        x=startx+nextx[i];
        y=starty+nexty[i];
        if(x>=0&&x<p&&y>=0&&y<q&&chess[x][y]==0){
            chess[x][y]=1;
            s[step]='A'+y;
            s[step+1]='1'+x;
            dfs(x,y,step+2);
            chess[x][y]=0;
        }
        //return;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    int time=0;
    while(t--){
        time++;
        scanf("%d%d",&p,&q);
        printf("Scenario #%d:\n",time);
        if(p==1&&q==1){
            printf("A1\n\n");
            continue;
        }
        if(p*q>26||p<=2||q<=2||p>=9||q>=9){
            printf("impossible\n\n");
            continue;
        }
        count=p*q*2;
        int i,j;
        flag=0;
        for(i=0;i<q;i++){
            for(j=0;j<p;j++){
                memset(chess,0,sizeof(chess));
                memset(s,'\0',sizeof(s));
                s[0]='A'+i;
                s[1]='1'+j;
                chess[j][i]=1;
                dfs(j,i,2);
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        if(!flag){
            printf("impossible\n\n");
        }
    }
    return 0;
}
