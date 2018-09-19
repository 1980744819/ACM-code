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
int startx,starty,endx,endy,robx,roby;
bool Map[35][35];
int Next[2][2]={{1,0},{0,1}};
int ans;
void dfs(int x,int y){
    int i;
    int a,b;
    if(x==endx&&y==endy){
        ans++;
        return;
    }
    for(i=0;i<2;i++){
        a=x+Next[i][0];
        b=y+Next[i][1];
        if(a>endx||b>endy||Map[a][b]==true)
            continue;
        Map[a][b]=true;
        dfs(a,b);
        Map[a][b]=false;
    }
}
int main(){
    int t;
    int i,j,k;
    scanf("%d",&t);
    int flag;
    while(t--){
        ans=0;
        memset(Map,false,sizeof(Map));
        scanf("%d %d %d %d",&endx,&endy,&robx,&roby);
        Map[robx][roby]=true;
        flag=0;
        if(robx-2>=0){
            if(roby-1>=0){
                    Map[robx-2][roby-1]=true;
                    if(robx-2==endx&&roby-1==endy)
                        flag=1;
            }
            if(roby+1<=endy){
                Map[robx-2][roby+1]=true;
                if(robx-2==endx&&roby+1==endy)
                        flag=1;
            }
        }
        if(robx-1>=0){
            if(roby-2>=0){
                Map[robx-1][roby-2]=true;
                if(robx-1==endx&&roby-2==endy)
                        flag=1;
            }
            if(roby+2<=endy){
                Map[robx-1][roby+2]=true;
                if(robx-1==endx&&roby+2==endy)
                        flag=1;
            }
        }
        if(robx+2<=endx){
            if(roby-1>=0){
                Map[robx+2][roby-1]=true;
                if(robx+2==endx&&roby-1==endy)
                        flag=1;
            }
            if(roby+1<=endy){
                Map[robx+2][roby+1]=true;
                if(robx+2==endx&&roby+1==endy)
                        flag=1;
            }
        }
        if(robx+1<=endx){
            if(roby-2>=0){
                Map[robx+1][roby-2]=true;
                if(robx+1==endx&&roby-2==endy)
                        flag=1;
            }
            if(roby+2<=endy){
                Map[robx+1][roby+2]=true;
                if(robx+1==endx&&roby+2==endy)
                        flag=1;
            }
        }
        if(robx==endx&&roby==endy)
            flag=1;
        if(flag)
            printf("0\n");
        else{
            Map[0][0]=true;
            dfs(0,0);
            printf("%d\n",ans);
        }
    }
    return 0;
}


