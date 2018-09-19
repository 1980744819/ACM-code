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
char s[105];
int dp[105][105];
bool match(int a,int b){
    if(s[a]=='('&&s[b]==')')
        return true;
    else if(s[a]=='['&&s[b]==']')
        return true;
    else
        return false;
}
void print(int i,int j){
    if(i>j)
        return;
    if(i==j){
        if(s[i]==')'||s[i]=='(')
            printf("()");
        else
            printf("[]");
        return;
    }
    int ans=dp[i][j];
    int k;
    if(match(i,j)&&ans==dp[i+1][j-1]){
        printf("%c",s[i]);
        print(i+1,j-1);
        printf("%c",s[j]);
        return;
    }
    for(k=i;k<j;k++){
        if(ans==dp[i][k]+dp[k+1][j]){
            print(i,k);
            print(k+1,j);
            return;
        }
    }
}
int main(){
    int i,j,k;
    int kase;
    scanf("%d",&kase);
    int len;
    int flag=0;
    getchar();
    while(kase--){
        gets(s);
        gets(s);
        len=strlen(s);
        if(!len){
            if(flag++)
                printf("\n");
            printf("\n");
            continue;
        }
        for(i=0;i<len;i++){
            dp[i][i]=1;
            dp[i+1][i]=0;
        }
        for(i=len-2;i>=0;i--){//dp
            for(j=i+1;j<len;j++){
                dp[i][j]=len;
                if(match(i,j))
                    dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                for(k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
        if(flag++)
            printf("\n");
        print(0,len-1);
        printf("\n");
        //memset(dp,0,sizeof(dp));
    }
    return 0;
}
