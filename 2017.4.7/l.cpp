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
int mp[40][40];
int main(){
    int n;
    int i,j;
    mp[0][0]=1;
    for(i=1;i<34;i++){
        mp[i][0]=1;
        for(j=1;j<=i;j++){
            mp[i][j]=mp[i-1][j-1]+mp[i-1][j];
        }
    }
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++){
            printf("%d",mp[i][0]);
            for(j=1;j<=i;j++){
                printf(" %d",mp[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}


