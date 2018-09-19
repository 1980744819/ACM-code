#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int a[35][35];
int t[35][35];
int ans[35][35];
int main(){
    int i,j,k;
    int n,m;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            t[i][j]=a[i][j];
        }
    }
    for(i=0;i<n;i++)
         ans[i][i]=1;
    while(m--){
        memset(t,0,sizeof(t));
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    t[i][j]+=ans[i][k]*a[k][j];
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                ans[i][j]=t[i][j];
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j==0)
                printf("%d",ans[i][j]);
            else
                printf(" %d",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
