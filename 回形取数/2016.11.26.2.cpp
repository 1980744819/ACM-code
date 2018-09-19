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
int ans;
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
                    if(robx-2==0&&roby-1==0)
                        flag=1;
            }
            if(roby+1<=endy){
                Map[robx-2][roby+1]=true;
                if(robx-2==endx&&roby+1==endy)
                        flag=1;
                if(robx-2==0&&roby+1==0)
                        flag=1;
            }
        }
        if(robx-1>=0){
            if(roby-2>=0){
                Map[robx-1][roby-2]=true;
                if(robx-1==endx&&roby-2==endy)
                        flag=1;
                if(robx-1==0&&roby-2==0)
                        flag=1;
            }
            if(roby+2<=endy){
                Map[robx-1][roby+2]=true;
                if(robx-1==endx&&roby+2==endy)
                        flag=1;
                if(robx-1==0&&roby+2==0)
                        flag=1;
            }
        }
        if(robx+2<=endx){
            if(roby-1>=0){
                Map[robx+2][roby-1]=true;
                if(robx+2==endx&&roby-1==endy)
                        flag=1;
                if(robx+2==0&&roby-1==0)
                        flag=1;
            }
            if(roby+1<=endy){
                Map[robx+2][roby+1]=true;
                if(robx+2==endx&&roby+1==endy)
                        flag=1;
                if(robx+2==0&&roby+1==0)
                        flag=1;
            }
        }
        if(robx+1<=endx){
            if(roby-2>=0){
                Map[robx+1][roby-2]=true;
                if(robx+1==endx&&roby-2==endy)
                        flag=1;
                if(robx+1==0&&roby-2==0)
                        flag=1;
            }
            if(roby+2<=endy){
                Map[robx+1][roby+2]=true;
                if(robx+1==endx&&roby+2==endy)
                        flag=1;
                if(robx+1==0&&roby+2==0)
                        flag=1;
            }
        }
        if(robx==endx&&roby==endy)
            flag=1;
        if(flag)
            printf("0\n");
        else{
            memset(dp,0,sizeof(dp));
                dp[0][0]=1;
            for(i=0;i<=endx;i++){
                for(j=0;j<=endy;j++){
                    if(i==0&&j==0)
                        dp[i][j]=1;
                    else if(i==0&&j!=0){
                        if(Map[i][j-1]==false)
                            dp[i][j]+=dp[i][j-1];
                        else
                            dp[i][j]=0;
                    }
                    else if(j==0&&i!=0){
                        if(Map[i-1][j]==false)
                            dp[i][j]+=dp[i-1][j];
                        else
                            dp[i][j]=0;
                    }
                    else{
                        if(Map[i-1][j]==false)
                    }
                }
            }
        }
    }
    return 0;
}


