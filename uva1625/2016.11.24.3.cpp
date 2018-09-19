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
char a[5005],b[5005];
int dp[5005][5005];
int starta[26],enda[26],startb[26],endb[26];
int main(){
    int kase;
    scanf("%d",&kase);
    int lena,lenb;
    int i,j,k;
    while(kase--){
        scanf("%s",a);
        scanf("%s",b);
        lena=strlen(a);
        lenb=strlen(b);
        for(i=0;i<26;i++){
            starta[i]=99999999;
            startb[i]=99999999;
            enda[i]=-99999999;
            endb[i]=-99999999;
        }
        for(i=0;i<lena;i++){
                a[i]-='A';
            if(starta[a[i]]==99999999){
                starta[a[i]]=i+1;
            }
            enda[a[i]]=i+1;
        }
        for(i=0;i<lenb;i++){
                b[i]-='A';
            if(startb[b[i]]==99999999){
                startb[b[i]]=i+1;
            }
            endb[b[i]]=i+1;
        }
        for(i=0;i<=lena;i++){
            for(j=0;j<=lenb;j++){
                dp[i][j]=0;
                for(k=0;k<26;k++){
                    if((i>=starta[k]||j>=startb[k])&&(i<enda[k]||j<endb[k]))
                        dp[i][j]++;
                }
                if(i==0&&j==0)
                    continue;
                else if(i==0)
                    dp[i][j]+=dp[i][j-1];
                else if(j==0)
                    dp[i][j]+=dp[i-1][j];
                else
                    dp[i][j]+=min(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[lena][lenb]);
    }
    return 0;
}

