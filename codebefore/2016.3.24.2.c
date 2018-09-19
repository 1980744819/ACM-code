#include<stdio.h>
#include<string.h>
#include<math.h>
#define inf 999999
int map[205][205],d[205],book[205],x[205],y[205];
int main(){
    int i,j,k;
    int n;
    int test=0;
    int a,b;
    while(~scanf("%d",&n)&&n){
            int min;
            test++;
        for(i=1;i<=n;i++){
            scanf("%d%d",&x[i],&y[i]);
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(i==j)
                    map[i][j]=0;
                else map[i][j]=inf;
            }
        }
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                a=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                if(map[i][j]>a)
                    map[i][j]=map[j][i]=a;
            }
        }
        for(i=1;i<=n;i++){
            book[i]=0;
            d[i]=map[1][i];
        }
        book[1]=1;
        for(i=1;i<n;i++){
            min=inf;
            for(j=1;j<=n;j++){
                if(book[j]==0&&d[j]<min){
                    min=d[j];
                    b=j;
                }
            }
            book[b]=1;
            for(j=1;j<=n;j++){
                if(map[b][j]<inf){
                    if(d[j]>d[b]+map[b][j])
                        d[j]=d[b]+map[b][j];
                }
            }
        }
        double ans=sqrt( (double) d[n]);
        printf("Scenario #%d\nFrog Distance = %.3f\n",test,ans);
    }
    return 0;
}
