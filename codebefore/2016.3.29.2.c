#include<stdio.h>
#include<string.h>
int a[100000],b[100000],c[100000];
int main(){
    int i,j;
    int m,n;
    int maxa,maxb;
    int max;
    maxa=0;
    maxb=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    while(~scanf("%d %d",&n,&m)){
            if(m==-1&&n==-1)
                break;
            if(maxa<m)
                maxa=m;
            a[m]=n;
    }
    while(~scanf("%d%d",&n,&m)){
        if(m==-1&&n==-1)
            break;
        if(maxb<m)
            maxb=m;
        b[m]=n;
    }
    int flag=1;
    max=maxa>maxb?maxa:maxb;
    //printf("%d\n",max);
    n=0;
    for(i=0;i<=max;i++){
        if(b[i]!=0)
        a[i]+=b[i];
        if(a[i]!=0)
            n+=1;
    }
    for(i=max;i>=0;i--){
        if(a[i]!=0){
            --n;
            flag=0;
            printf("%d %d ",a[i],i);
            /*if(n>0){
                printf(" ");
            }*/
        }
    }
    if(flag){
        printf("0");
    }
    printf("\n");
    return 0;
}
