#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
struct stu{
    double x,y;
}node[1200];
double dp[1200][1200];
int cmp(struct stu a,struct stu b){
    return a.x<b.x;
}
double dis(int i,int j){
    return sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y));
}
int main(){
    int n;
    int i,j;
    while(~scanf("%d",&n)){
        for(i=1;i<=n;i++){
            scanf("%lf %lf",&node[i].x,&node[i].y);
        }
        sort(node,node+n,cmp);
        dp[2][1]=dis(1,2);
        for(i=3;i<=n;i++){
            dp[i][i-1]=9999999.0;
            for(j=1;j<i-1;j++){
                dp[i][i-1]=min(dp[i][i-1],dp[i-1][j]+dis(i,j));
                dp[i][j]=dp[i-1][j]+dis(i-1,i);
            }
        }
        double ans=9999999.0;
        for(i=1;i<n;i++){
            ans=min(ans,dp[n][i]+dis(n,i));
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
