#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int Map[105][105];
int dp[105][105];
int Next[105][105];
int main(){
    int m,n;
    int i,j;
    int v,first;
    while(~scanf("%d %d",&m,&n)){
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf("%d",&Map[i][j]);
            }
        }
        int ans=0x7FFFFFFF;
        first=0;
        for(j=n-1;j>=0;j--){
            for(i=0;i<m;i++){
                if(j==n-1){
                    dp[i][j]=Map[i][j];
                }
                else{
                    int row[3]={i,i-1,i+1};
                    if(i==0)
                        row[1]=m-1;
                    if(i==m-1)
                        row[2]=0;
                    sort(row,row+3);
                    dp[i][j]=0x7FFFFFFF;
                    for(int k=0;k<3;k++){
                        v=dp[row[k]][j+1]+Map[i][j];
                        if(v<dp[i][j]){
                            dp[i][j]=v;
                            Next[i][j]=row[k];
                        }
                    }
                }
                if(j==0&&dp[i][j]<ans){first=i;ans=dp[i][j];}
            }
        }
        printf("%d",first+1);
        i=Next[first][0];
        for(j=1;j<n;j++){
            printf(" %d",i+1);
            i=Next[i][j];
        }
        printf("\n");
        printf("%d\n",ans);
        /*for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%d ",Map[i][j]);
            }
            printf("\n");
        }*/
    }
    return 0;
}
