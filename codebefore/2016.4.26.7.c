#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int arr[305][305];
struct ju{
    int row;
    int col;
    int value;
};
int main(){
    struct ju a[12501];
    struct ju b[12501];
    int m,n;
    int num;
    int i,j;
    while(~scanf("%d %d",&m,&n)){
        int acou=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf("%d",&num);
                if(num!=0){
                    a[acou].row=i;
                    a[acou].col=j;
                    a[acou].value=num;
                    acou++;
                }
            }
        }
        num=0;
        while(num<acou){
            arr[a[num].col][a[num].row]=a[num].value;
            num++;
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

