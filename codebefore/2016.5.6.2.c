#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int a[1000001];
int main(){
    int n,k;
    int i,j;
    while(~scanf("%d%d",&n,&k)){
            for(i=1;i<=n;i++)
                scanf("%d ",&a[i]);
            //k=0;
            i=1;
            int num1=0,num2=0;
        while(i!=0){
                printf("%d\n",i);
                num1=i*(i-1)/2;
                num2=i*(i+1)/2;
            if(k<num2&&k>num1){
                //printf("%d %d\n",num1,num2);
                k-=num1;
                if(k%n==0){
                    if(i!=1)
                        printf("%d\n",a[n]);
                    else
                        printf("%d\n",a[1]);
                }
                else
                    printf("%d\n",a[k%n]);
                break;
            }
            else if(k==num2){
                if(i!=1)
                    printf("%d\n",a[n]);
                else
                    printf("%d\n",a[1]);
                break;
            }
            i++;
        }
    }
    return 0;
}
