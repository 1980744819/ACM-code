#include<stdio.h>
#include<string.h>
int main(){
    int arr[3];
    while(~scanf("%d%d%d",&arr[0],&arr[1],&arr[2])){
        int i,j;
        for(i=0;i<3;i++)
            for(j=0;j<i;j++){
                if(arr[i]<arr[j]){
                    int t=arr[i];
                    arr[i]=arr[j];
                    arr[j]=t;
            }
        }
        if(arr[2]>=arr[1]+arr[0])
            printf("ERROR\n");
        else if(arr[1]==arr[0]){
            if(arr[0]==arr[2])
                printf("DB\n");
            else
                printf("DY\n");
        }
        else if(arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2])
            printf("ZJ\n");
        else
            printf("PT\n");
    }
    return 0;
}
