#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int cru[105];
bool vis[105];
int dfs(int root,int fa,int p,int num){
    if(root==p){
        return num;
    }
    else if(fa==p&&num>1){
        return 0;
    }
    else{
        vis[p]=true;
        return dfs(root,p,cru[p],num+1);
    }
}

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}
int main(){
    int n;
    int i,j;
    int coun,ans;
    int tmp;
    int flag;
    while(~scanf("%d",&n)){
        for(i=1;i<=n;i++){
            scanf("%d",&cru[i]);
        }
        ans=1;
        flag=0;
        for(i=1;i<=n;i++){
            if(!vis[i]){
                if(i!=cru[i]){
                    vis[i]=true;
                    coun=dfs(i,i,cru[i],1);
                    if(coun%2==0)
                        coun/=2;
                    //printf("%d %d\n",i,coun);
                }
                else
                    coun=1;
                if(coun!=0){
                    tmp=gcd(ans,coun);
                    ans=ans*coun;
                    ans/=tmp;
                    //printf("%d ",ans);
                }
                else{
                    printf("-1\n");
                    flag=1;
                    break;
                }
            }
        }
        if(!flag)
            printf("%d\n",ans);
        memset(vis,false,sizeof(vis));
    }
    return 0;
}

