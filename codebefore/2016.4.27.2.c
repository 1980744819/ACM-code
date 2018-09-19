#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int tot=0;
int n;
int vis[3][200]={0};
int c[20];
void search(int cur){
    int i,j;
    if(cur==n){
        tot++;
        if(tot<4){
            for(i=0;i<n-1;i++)
                printf("%d ",c[i]+1);
            printf("%d\n",c[n-1]+1);
            //return;
        }
    }
    else{
        for(i=0;i<n;i++){
            if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+n]){
                c[cur]=i;
                //printf("%d %d\n",cur,i);
                vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;
                search(cur+1);
                vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;
            }
        }
    }
}
int main(){
    while(~scanf("%d",&n)){
         tot=0;
        search(0);
        printf("%d\n",tot);
    }
    return 0;
}


