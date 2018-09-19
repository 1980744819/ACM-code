#include<stdio.h>
#include<string.h>
int main(){
    int t,t1,t2,t3,t4;
    int n;
    scanf("%d",&t1);
    getchar();
    scanf("%d",&t2);
    getchar();
    scanf("%d",&t3);
    getchar();
    scanf("%d",&t4);
    getchar();
    scanf("%d",&n);
    int ans=t3*60+t4-t1*60-t2+n*20;
    printf("%d\n",ans);
    return 0;
}
