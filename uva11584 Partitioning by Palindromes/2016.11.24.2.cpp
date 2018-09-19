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
int dp[1005];
char str[1005];
bool num[1005][1005];
bool judge(int i,int j){
    while(i<=j){
        if(str[i]!=str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int main(){
    int kase;
    scanf("%d",&kase);
    int i,j;
    int len;
    while(kase--){
        scanf("%s",str);
        len=strlen(str);
        for(i=0;i<len;i++){
            for(j=0;j<=i;j++){
                num[j][i]=judge(j,i);
            }
        }
        for(i=0;i<len;i++){
            if(num[0][i])
                dp[i]=1;
            else
                dp[i]=i+1;
            for(j=0;j<i;j++){
                if(num[j+1][i]==true)
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
        printf("%d\n",dp[len-1]);
    }
    return 0;
}

