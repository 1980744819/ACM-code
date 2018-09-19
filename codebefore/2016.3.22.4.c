#include<stdio.h>
#include<string.h>
int main(){
    int x,m,n;
    int t,ans;
    int i;
    scanf("%d%d%d",&x,&m,&n);
    t=x;
    ans=0;
    for(i=0;i<n;i++){
        ans+=t;
        t+=m;
    }
    printf("%d\n",ans);
    return 0;
}
