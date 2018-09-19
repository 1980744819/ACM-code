#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int map[21][21];
int ans;
int set[42];
int n;
void dfs(int num,int sum){
    set[num]=1;
    int i;
    int data=sum;
    for(i=1;i<=n;i++){
        if(set[i]){
            data-=map[num][i];
        }
        else{
            data+=map[num][i];
        }
    }
    //printf("%d %d\n",num,data);
    if(ans<data){
        ans=data;
    }
    for(i=num+1;i<=n;i++){
        if(data>sum){
            dfs(i,data);
            set[i]=0;
        }
    }
}
int main(){
    while(~scanf("%d",&n)){
        int i,j;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&map[i][j]);
            }
        }
        memset(set,0,sizeof(set));
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}

