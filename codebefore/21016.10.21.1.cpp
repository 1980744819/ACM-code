#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<malloc.h>
using namespace std;
int num[100002][10001];
int m;
void fb(){
    m=1;
    num[m][0]=1;
    num[m][1]=1;
    m++;
    num[m][0]=1;
    num[m][1]=1;
    int i,j;
    while(m<=100001){
        m++;
        num[m][0]=num[m-1][0];
        for(i=1;i<=num[m-1][0];i++){
            num[m][i]+=num[m-1][i]+num[m-2][i];
            if(num[m][i]>=1000000){
                num[m][i]-=1000000;
                num[m][i+1]++;
                if(i==num[m-1][0]){
                    num[m][0]++;
                }
            }
        }
        //for(i=num[m][0];i>=0;i--){
            printf("%d %d",m,num[m][0]);
        //}
        printf("\n");
    }
}
int main(){
    int n;
    fb();
    while(scanf("%d",&n)&&n!=0){
        int i;

    }
    return 0;
}




