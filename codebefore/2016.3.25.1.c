#include<stdio.h>
#include<string.h>

int main(){
    int m,n[10005];
    scanf("%d",&m);
    int i,j;
    int max=0;
    long long  an[10005];
    for(i=1;i<=m;i++){
        scanf("%d",&n[i]);
        if(max<n[i])
            max=n[i];
    }
    an[0]=0;
    an[1]=1;
    for(i=2;i<=max;i++)
        an[i]=2*an[i-1]-3*an[i-2]+1;
    for(i=1;i<=m;i++)
        printf("%lld\n",an[n[i]]);
    return 0;
}
