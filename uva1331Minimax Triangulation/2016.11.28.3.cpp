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
double dp[55][55];
struct stu{
    int x,y;
}node[55];
int m;
double area(struct stu a,struct stu b,struct stu c){
    return 0.5*fabs((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
}
bool check(int a,int b,int c){
    int i;
    for(i=1;i<=m;i++){
        if(i==a||i==b||i==c)
            continue;
        double d=area(node[a],node[b],node[i])+area(node[i],node[b],node[c])+area(node[a],node[c],node[i])-area(node[a],node[b],node[c]);
        if(d<0)
            d=-d;
        if(d<=0.01)
            return false;
    }
    return true;
}
int main(){
    int kase;
    int i,j,k;
    scanf("%d",&kase);
    while(kase--){
        scanf("%d",&m);
        for(i=1;i<=m;i++)
            scanf("%d %d",&node[i].x,&node[i].y);
        for(i=m;i>=1;i--){
            dp[i][i+1]=0.0;
            for(j=i+2;j<=m;j++){
                dp[i][j]=99999999;
                for(k=i+1;k<j;k++){
                    if(check(i,j,k))
                        dp[i][j]=min(dp[i][j],max(max(area(node[i],node[j],node[k]),dp[i][k]),dp[k][j]));
                        //printf("%d %d %d\n",i,j,k);
                }
            }
        }
        printf("%.1lf\n",dp[1][m]);
    }
    return 0;
}
