#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<malloc.h>
using namespace std;
int m[105][105];
int step[105][105];
int main(){
    int n;
    while(~scanf("%d",&n)){//step[0]
        //scanf("%d",&m[0][0]);
        //step[0][0]=m[0][0];
        int i,j;
        for(i=0;i<n;i++){
            for(j=0;j<=i;j++){
                scanf("%d",&m[i][j]);
                //step[i][j]=max(m[i-1][])
            }
        }
        for(j=0;j<n;j++)
            step[n-1][j]=m[n-1][j];
        for(i=n-2;i>=0;i--){
            for(j=0;j<=i;j++){
                step[i][j]=m[i][j]+max(step[i+1][j],step[i+1][j+1]);
            }
        }
        printf("%d\n",step[0][0]);
    }
    return 0;
}

