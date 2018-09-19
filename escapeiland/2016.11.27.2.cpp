#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int Map[205][205];
bool book[205][205];
bool bk[205][205];
struct stu{
    int x,y,t;
}node,temp;
int u,v;
int nextx[4]={-1,1,0,0};
int nexty[4]={0,0,-1,1};
int m,n;
void dfs(int a,int b){
    int x,y,i,j;
    for(i=0;i<4;i++){
        x=a+nextx[i];
        y=b+nexty[i];
        if(x<0||x>m+1||y<0||y>n+1)
            continue;
        if(Map[x][y]==1||book[x][y]==true)
            continue;
        Map[x][y]=0;
        book[x][y]=true;
        //printf("%d %d\n",x,y);
        dfs(x,y);
    }
    return;
}
int main(){
    int i,j,k;
    char c;
    int sx,sy,ex,ey;
    int t;
    while(~scanf("%d %d",&m,&n)){
        memset(Map,0,sizeof(Map));
        memset(book,false,sizeof(book));
        getchar();
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                scanf("%c",&c);
                if(c=='#')
                    Map[i][j]=1;
                else
                    Map[i][j]=2;
            }
            getchar();
        }
        book[0][0]=true;
        dfs(0,0);
        memset(book,false,sizeof(book));
        scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
        node.x=sx;
        node.y=sy;
        node.t=0;
        book[sx][sy]=true;
        queue<struct stu>que;
        que.push(node);
        int flag=0;
        int sec;
        t=0;
        while(!que.empty()){
            temp=que.front();
            //printf("%d %d %d\n",temp.x,temp.y,temp.t);
            if(temp.t<t)
            {
                    for(i=0;i<=m+1;i++){
                    for(j=0;j<=n+1;j++){
                        if(Map[i][j]==0&&bk[i][j]==0){
                            for(k=0;k<4;k++){
                                u=i+nextx[k];
                                v=j+nexty[k];
                                if(u<0||u>m+1||v<0||v>n+1)
                                    continue;
                                if(Map[u][v]==0||bk[u][v]==1)
                                    continue;
                                bk[u][v]=1;
                                Map[u][v]=0;
                            }
                        }
                    }
                }
                memset(bk,0,sizeof(bk));
                t++;
            }
            if(Map[temp.x][temp.y]==0){
                que.pop();
                continue;
            }

            if(temp.x==ex&&temp.y==ey){
                flag=1;
                sec=temp.t;
                break;
            }


            /*for(i=1;i<=m;i++){for(i=0;i<=m+1;i++){
                for(j=0;j<=n+1;j++){
                    if(Map[i][j]==0&&bk[i][j]==0){
                        for(k=0;k<4;k++){
                            u=i+nextx[k];
                            v=j+nexty[k];
                            if(u<0||u>m+1||v<0||v>n+1)
                                continue;
                            if(Map[u][v]==0||bk[u][v]==1)
                                continue;
                            bk[u][v]=1;
                            Map[u][v]=0;
                        }
                    }
                }
            }
            memset(bk,0,sizeof(bk));
                for(j=1;j<=n;j++){
                    printf("%d ",Map[i][j]);
                }
                printf("\n");
            }*/
            for(i=0;i<4;i++){
                u=temp.x+nextx[i];
                v=temp.y+nexty[i];
                if(u<1||u>m||v<1||v>n)
                    continue;
                if(Map[u][v]==0||book[u][v]==1)
                    continue;
                book[u][v]=1;
                node.x=u;
                node.y=v;
                node.t=temp.t+1;
                que.push(node);
            }
                que.pop();
        }
        if(flag)
            printf("Tank can be transferred out of the island at second %d! ( ^_^ )\n",sec);
        else
            printf("Oh, no! Tank will be drowned! QwQ\n");
    }
    return 0;
}

