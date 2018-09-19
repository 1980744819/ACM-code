#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
int dp[205][205];
int s[205][205];
int a[205];
int b[205];
int n;
void print(int i,int j){
    if(i==j){
        printf("A%d",i-1);
    }
    else{
        printf("(");
        print(i,s[i][j]);
        print(s[i][j],j);
        printf(")");
    }
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n!=0){
        int i,j,k;
        int length;
        memset(s,0,sizeof(s));
        memset(b,0,sizeof(b));
        n++;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            dp[i][i]=0;
        }
        int t;
        for(length=2;length<=n;length++){
            for(i=1;i<=n-length+1;i++){
                j=i+length-1;
                dp[i][j]=9999999;
                for(k=i;k<=j-1;k++){
                    t=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
                    if(t<dp[i][j]){
                        dp[i][j]=t;
                        //printf("%d\n",dp[i][j]);
                        s[i][j]=k;
                    }
                }
            }
        }
        //printf("%d\n",dp[1][n-1]);
        print(1,n-1);
        cout<<endl;
    }
    return 0;
}


