#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int f[30005];
int num[30005];
int m,n;
int findfa(int i){
    if(f[i]==i)
        return i;
    else
        return findfa(f[i]);
}
void merge(int i,int j){
    int x=findfa(i);
    int y=findfa(j);
    if(x==y)
        return;
    if(x<y){
        num[x]+=num[y];
        f[y]=x;
    }
    else{
        num[y]+=num[x];
        f[x]=y;
    }
}
int main(){
    int i,j,k;
    while(~scanf("%d%d",&n,&m)){
        if(m==0&&n==0)
            break;
        for(i=0;i<n;i++){
            f[i]=i;
            num[i]=1;
        }
        int leader;
        int member;
        for(i=0;i<m;i++){
            scanf("%d",&k);
            if(k)
                scanf("%d",&leader);
            k--;
            while(k--){
                scanf("%d",&member);
                merge(member,leader);
            }
        }
        printf("%d\n",num[0]);
    }
    return 0;
}
