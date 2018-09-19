#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<malloc.h>
#include<math.h>
int f[50005],n,m,k,sum=0;
void init(){
    int i;
    for(i=1;i<=n;i++){
        f[i]=i;
    }
}
int getf(int v){
    if(f[v]==v)
        return v;
    else{
        f[v]=getf(f[v]);
        return f[v];
    }
}
int merge(int v,int u){
    int t1,t2;
    t1=getf(v);
    t2=getf(u);
    if(t1!=t2){
        f[t2]=t1;
    }
}
int main(){
    int i,x,y;
    int kase=0;
    while(~scanf("%d%d",&n,&m)){
        kase++;
        if(m==0&&n==0)
            break;
        init();
        for(i=1;i<=m;i++){
            scanf("%d %d",&x,&y);
            merge(x,y);
        }
        for(i=1;i<=n;i++){
            if(f[i]==i)
                sum++;
        }
        printf("Case %d: %d\n",kase,sum);
        sum=0;
    }
    return 0;
}
