#include<stdio.h>
int f(int n){
    int ans;
    if(n==0)
        ans=0;
    else ans=n+f(n-1);
    return ans;
}
int main(){
    int n,ans;
    scanf("%d",&n);
    ans=f(n);
    printf("%d\n",ans);
    return 0;
}
