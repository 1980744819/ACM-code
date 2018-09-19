#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int c[1000];
int i,j=0;
int main(){
    int num;
    int a,b;
    int rec=1;
    while(scanf("%d",&num)==1&&num){
        if(j>=num&&j>0){
            printf("%d\n",c[num-1]);
        }
        else{
            for(i=rec;i<10000;i++){
                if(i%2==0||i%3==0||i%5==0||i==1){
                    c[j]=i;
                    j++;
                    a=i;
                    if(j==num)
                        break;
                }
            }
            /*for(i=0;i<j;i++)
            printf("%d ",c[i]);
            printf("\n");*/
            printf("%d\n",c[num-1]);
            rec=a+1;
        }
    }
	return 0;
}

