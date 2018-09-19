#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int dp[15005];
char st[605][30];
char ms[15005];

int main(){
    int i,j;
    int pm,pd;
    int w,l;
    int len;
    while(~scanf("%d %d",&w,&l)){
        scanf("%s",ms);
        for(i=0;i<w;i++){
            scanf("%s",st[i]);
            //puts(st[i]);
            //printf("%d\n",strlen(st[i]));
        }
        dp[l]=0;
        for(i=l-1;i>=0;i--){
            dp[i]=dp[i+1]+1;
            for(j=0;j<w;j++){
                len=strlen(st[j]);
                if(len<=l-i&&st[j][0]==ms[i]){
                    pm=i;
                    pd=0;
                    while(pm<l){
                        if(st[j][pd]==ms[pm])
                            pd++;
                        pm++;
                        if(pd==len){
                            dp[i]=min(dp[i],dp[pm]+pm-i-len);
                            break;
                        }
                    }
                }
            }
            //printf("%d %d\n",dp[i],i);
        }
        printf("%d\n",dp[0]);
    }
    return 0;
}

