#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<malloc.h>
#include<math.h>
int col[9];
//int row[9];
int map[9][9];
int n,k;
int ans;
void dfs(int row,int num){
    int i;
    if(num==k){
        ans++;
        return;
    }
    if(row>=n)
        return;
    for(i=0;i<n;i++){
        if(map[row][i]&&col[i]==0){
            col[i]=1;
            dfs(row+1,num+1);
            col[i]=0;
        }
    }
    dfs(row+1,num);
    return;
}
int main(){
    while(~scanf("%d%d",&n,&k)){
        if(n==-1&&k==-1)
        break;
        int i,j;
        char  ch[9];
        memset(map,0,sizeof(map));
        memset(col,0,sizeof(col));
        for(i=0;i<n;i++){
                scanf("%s",ch);
            for(j=0;j<n;j++){
                if(ch[j]=='#')
                    map[i][j]=1;
            }
        }
        ans=0;
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
