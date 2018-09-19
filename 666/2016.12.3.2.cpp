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
long long L[200005];
char s[200005];
bool vis[200005];
int dfs(int i){
    if(s[i]!='6')
        return 0;
    vis[i]=true;
    return 1+dfs(i+1);
}
int main(){
    int i,j,k;
    int n;
    int kase;
    L[1]=1;
    for(i=2;i<=200005;i++){
        L[i]=i+L[i-1];
        //printf("%d\n",L[i]);
    }
    //printf("%lld\n",L[200000]);
    scanf("%d",&kase);
    int lenth=0;
    long long ans=0;
    while(kase--){
        memset(vis,false,sizeof(vis));
        scanf("%d",&n);
        scanf("%s",&s);
        //puts(s);
        ans=0;
        for(i=0;i<n;i++){
            if(s[i]=='6'&&vis[i]==false){
                lenth=dfs(i);
                //printf("%d %d\n",i,lenth);
                ans+=L[lenth];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
