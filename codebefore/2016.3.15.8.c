#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[100][100];
int main(){
    int i,j;
    int n,t;
    while(~scanf("%d",&n)){
        memset(a,'\n',sizeof(a));
        t=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                a[i][j]=0;
            }
        }
        for(i=0;i<n;i++){
            t++;
            a[0][i]=t;
        }
        for(i=1;i<n;i++){
            t++;
            a[i][n-1]=t;
        }
        for(i=n-2;i>=0;i--){
                t++;
                a[n-1][i]=t;
        }
        for(i=n-2;i>0;i--){
            t++;
            a[i][0]=t;
        }
        for(i=0;i<3*n;i++){
            for(j=0;j<3*n;j++){
                if(a[i][j]==0)
                    printf("   ");
                else printf("3%d",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
