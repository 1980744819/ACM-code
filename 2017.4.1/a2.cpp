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
bool vis[105];
int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}
int main(){
    int n;
    int i,j;
    int x,y;
    int ans;
    int coun;
    int a[105];
    int flag;
    int tmp;
    while(~scanf("%d",&n)){
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        ans=1;
        flag=0;
        for(i=1;i<=n;i++){
            if(!vis[i]){
                x=i;
                y=a[i];
                coun=1;
                vis[x]=true;
                while(x!=y){
                    vis[y]=true;
                    coun++;
                    if(coun>n+2){
                        coun=0;
                        break;
                    }
                    y=a[y];
                }
                if(coun==0){
                    flag=1;
                    printf("-1\n");
                    break;
                }
                else{
                    if(coun%2==0)
                        coun/=2;
                    tmp=gcd(ans,coun);
                    ans=ans*coun/tmp;
                }
            }
        }
        if(!flag)
            printf("%d\n",ans);
        memset(vis,false,sizeof(vis));
    }
    return 0;
}

