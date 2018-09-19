#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int a[305][305];
int b[305][305];
int c[305][305];
int main(){
    int i,j,k;
    int m1,n1;
    int m2,n2;
    int sum;
    while(~scanf("%d %d",&m1,&n1)){
        for(i=0;i<m1;i++){
            for(j=0;j<n1;j++){
                scanf("%d",&a[i][j]);
            }
        }
        //scanf("%d %d",&m2,&n2);
        for(i=0;i<m1;i++){
            for(j=0;j<n1;j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        /*for(i=0;i<m1;i++){
            for(j=0;j<n2;j++){
                    sum=0;
                 for(k=0;k<n1;k++)
                    sum+=a[i][k]*b[k][j];
                 c[i][j]+=sum;
            }
        }
        for(i=0;i<m1;i++){
            for(j=0;j<n2;j++){
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }*/
    }
    return 0;
}

