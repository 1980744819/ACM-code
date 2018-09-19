#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int map[51][51];
int book[51];
int sum=0;
int n;
void dfs(int cur){
    int i;
    printf("%d ",cur-1);
    sum++;
    if(sum==n) return;
    for(i=1;i<=n;i++){
        if(map[cur][i]==1&&book[i]==0){
            book[i]=1;
            dfs(i);
        }
    }
    return;
}
int main(){
    while(~scanf("%d",&n)){
        int i,j;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&map[i][j]);
            }
        }
        book[1]=1;
        dfs(1);
    }
    return 0;
}

