#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int book[50005];
int main(){
    int n,m;
    int col;
    int i,j;
    int a,b;
    int kase=0;
    while(scanf("%d%d",&n,&m)){
        kase++;
        if(m==0&&n==0)
            break;
        col=1;
        while(m--){
            scanf("%d%d",&a,&b);
            if(book[a]==0&&book[b]==0){
                book[a]=book[b]=col;
                col++;
            }
            else if(book[a]!=0&&book[b]==0){
                book[b]=book[a];
            }
            else if(book[b]!=0&&book[a]==0){
                book[a]=book[b];
            }
        }
        int ans=0;
        for(i=1;i<=n;i++){
            if(book[i]==0)
                ans++;
        }
        ans+=col;
        printf("Case %d: %d\n",kase,ans-1);
        //printf("%d\n",ans-1);
        //memset(book,0,sizeof(book));
        for(i=1;i<=n;i++)
            book[i]=0;
    }
    return 0;
}
