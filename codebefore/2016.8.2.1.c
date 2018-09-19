#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int map[27][27];
int col[27];
int n;
int toltal;
int ok(int id,int i){
    int k;
    for(k=0;k<n;k++){
        if(map[id][k]==1&&col[k]==i)
            return 0;
    }
    return 1;
}
void dfs(int id){
    if(id==n) return;
    int i;
    int flag;
    flag=0;
    for(i=1;i<=toltal;i++){
        if(ok(id,i)){
            flag=1;
            col[id]=i;
            dfs(id+1);
            //col[id]=0;
        }
    }
    if(!flag){
        toltal++;
        dfs(id);
    }
}
int main(){
    char s[30];
    while(~scanf("%d",&n)){
        if(n==0)
            break;
        int i,j;
        int len;
        for(i=0;i<n;i++){
            getchar();
            scanf("%s",s);
            len=strlen(s);
            for(j=2;s[j]!='\0';j++){
                map[s[0]-'A'][s[j]-'A']=1;
            }
        }
        toltal=1;
        dfs(0);
        printf("%d ",toltal);
        if(toltal>1){
            printf("channels needed.\n");
        }
        else{
            printf("channel needed.\n");
        }
        /*for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%d",map[i][j]);
            }
            printf("\n");
        }
        for(i=0;i<n;i++){
            printf("%d ",col[i]);
        }
        printf("\n");*/
        memset(s,'\0',sizeof(s));
        memset(map,0,sizeof(map));
        memset(col,0,sizeof(col));
    }
    return 0;
}
