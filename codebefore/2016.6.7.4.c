#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int map[51][51];
int book[51];
int dis[51];
int n;
int sum=0;
int count=0;
int main(){
    //while(~scanf("%d",&n)){
    scanf("%d",&n);
        int i,j,k;
        sum=0;
        count=0;
        for(i=1;i<=n;i++)
            book[i]=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j]==0)
                    map[i][j]=99999999;
            }
        }
        for(i=1;i<=n;i++)
            map[i][i]=0;
        for(i=1;i<=n;i++)
            dis[i]=map[1][i];
        book[1]=1;
        count++;
        while(count<n){
            int min=99999999;
            for(i=1;i<=n;i++){
                if(book[i]==0&&dis[i]<min){
                    min=dis[i];
                    j=i;
                }
                book[j]=1;
                count++;
                sum+=dis[j];
            }
            for(k=1;k<=n;k++){
                if(book[k]==0&&dis[k]>map[j][k])
                    dis[k]=map[j][k];
            }
        }
        printf("%d\n",sum);
    //}
    return 0;
}

