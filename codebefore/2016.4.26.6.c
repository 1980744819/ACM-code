#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int a[305][305];
int main(){
    int m,n;
    int i,j;
    while(~scanf("%d %d",&m,&n)){
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(i=0;i<n;i++){
            j=0;
            while(j<m){
                printf("%d ",a[j][i]);
                j++;
            }
            printf("\n");
        }
    }
    return 0;
}
