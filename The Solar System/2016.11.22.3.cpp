#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
struct stu{
    int x,y,z;
    void f(int a,int b,int c){
        x=a;
        y=b;
        z=c;
    }
}cube[200];
bool cmp(struct stu a,struct stu b){
    return a.x*a.y<b.x*b.y;
}
int dp[200];
int main(){
    int n;
    int i,j,k;
    int m;
    int a,b,c;
    int Max;
    int kase=0;
    while(~scanf("%d",&n)&&n!=0){
        m=0;
        for(i=0;i<n;i++){
            scanf("%d %d %d",&a,&b,&c);
            cube[m++].f(a,b,c);
            cube[m++].f(a,c,b);
            cube[m++].f(b,a,c);
            cube[m++].f(b,c,a);
            cube[m++].f(c,b,a);
            cube[m++].f(c,a,b);
        }
        sort(cube,cube+m,cmp);
        Max=0;
        for(i=0;i<m;i++){
            dp[i]=cube[i].z;
            for(j=0;j<i;j++){
                if(cube[i].x>cube[j].x&&cube[i].y>cube[j].y){
                    dp[i]=max(dp[i],dp[j]+cube[i].z);
                }
            }
            if(Max<dp[i])
                Max=dp[i];
        }
        printf("Case %d: maximum height = %d\n",++kase,Max);
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
