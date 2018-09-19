#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<malloc.h>
//#include<windows.h>
using namespace std;
long long num[100005][1300];
int m;
void fb(){
    /*FILE *fp;
    fp=fopen("C:\\Users\\×ÊÏö\\Desktop\\test.out","w");
    fprintf(fp,"1,\n");
    fprintf(fp,"1,\n");*/
    m=1;
    num[m][0]=1;
    num[m][1]=1;
    m++;
    num[m][0]=1;
    num[m][1]=1;
    int i,j;
    int t;
    while(m<=100001){
        m++;
        num[m][0]=num[m-1][0];
        t=num[m-1][0];
        for(i=1;i<=t;i++){
            num[m][i]+=num[m-1][i]+num[m-2][i];
            if(num[m][i]>=100000000000000000){
                num[m][i]-=100000000000000000;
                num[m][i+1]++;
                if(i==t){
                    num[m][0]++;
                }
            }
        }
       // fprintf(fp,"%d %lld\n",m,num[m][0]);
        //int tb,b;
        /*for(i=num[m][0];i>=1;i--){
            fprintf(fp,"%lld",num[m][i]);
        }
        fprintf(fp,"\n");
        //Sleep(1000);*/
    }
}
int main(){
    int n;
    fb();
    int i;
    while(scanf("%d",&n)&&n!=0){
        for(i=num[n][0];i>=1;i--){
            printf("%lld",num[n][i]);
        }
        printf("\n");
    }
    return 0;
}
