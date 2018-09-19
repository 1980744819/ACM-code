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
int main(){
    char a[27][27];
    int m,n;
    int i,j;
    int num;
    for(i=0;i<26;i++){
        num=0;
        for(j=i;j>=0;j--){
            a[i][j]='A'+num;
            num++;
        }
        num=0;
        for(j=i+1;j<26;j++){
            a[i][j]='B'+num;
            num++;
        }
    }
    while(~scanf("%d %d",&n,&m)){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("%c",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

