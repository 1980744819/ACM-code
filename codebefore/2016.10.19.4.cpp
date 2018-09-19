#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<malloc.h>
using namespace std;
int num[100010][105];
int m;
int len;
int main(){
    int n;
    m=1;
    num[m][0]=1;//第一个数存储长度
    num[m][1]=1;
    m++;
    num[m][0]=1;
    num[m][1]=1;
    while(~scanf("%d",&n)&&n!=0){
        int i,j;
        if(n<=m){
            for(i=num[n][0];i>=1;i--){
                printf("%d",num[n][i]);
            }
            printf("\n");
        }
        else{
            for(m=m+1;m<=n;m++){
                    num[m][0]=num[m-1][0];
                for(i=1;i<=num[m-1][0];i++){
                    num[m][i]+=num[m-1][i]+num[m-2][i];
                    if(num[m][i]>=10){
                        num[m][i]%=10;
                        num[m][i+1]++;
                        if(i+1>num[m][0])
                            num[m][0]++;
                    }
                }
            }
            m--;
            for(i=num[n][0];i>=1;i--){
                printf("%d",num[n][i]);
            }
            printf("\n");
        }
    }
    return 0;
}



