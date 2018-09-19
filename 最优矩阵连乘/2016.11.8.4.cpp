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
int n;
void print(int i,int j,int t){
    if(i==j){
        cout<<"A"<<i-1;
    }
    else{
        if(t!=0)
        cout<<"(";
        print(i,s[i][j],t+1);
        print(s[i][j]+1,j,t+1);
        if(t!=0)
        cout<<")";
    }
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n!=0){
        int i,j,k;
        int length;
        //memset(s,0,zizeof(s));
        n++;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            dp[i][i]=0;
        }
        int t;
        for(length=2;length<=n;length++){
            for(i=1;i<=n-length+1;i++){
                j=i+length-1;
                dp[i][j]=0x7fffffff;
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
        print(1,n-1,0);
        cout<<endl;
    }
    return 0;
}

