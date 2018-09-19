#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int tot=0;
int n;
int vis[2][200];
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
    else for(i=0;i<n;i++){
                c[cur]=i;
                int ok=1;
            for(j=0;j<cur;j++)
                if(c[cur]==c[j]||cur-c[cur]==j-c[j]||cur+c[cur]==j+c[j]){
                        ok=0;
                        break;
                }
             if(ok)
                search(cur+1);
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

