#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<malloc.h>
#include<math.h>
char stac[10000];
top=-1;
int main(){
    int i,j,k;
    int kase;
    scanf("%d",&kase);
    int n;
    int left;
    int num;
    int count ,sum;
    while(kase--){
        left=0;
        scanf("%d",&n);
        while(n--){
            scanf("%d",&num);
            while(left<num){
                top++;
                stac[top]='(';
                left++;
            }
            top++;
            stac[top]=')';
        }
        //puts(stac);
        int len=strlen(stac);
        for(i=0;i<len;i++){
            sum=0;
            count=0;
            if(stac[i]==')'){
                j=i-1;
                sum++;
                while(sum>0&&j>=0){
                    if(stac[j]=='('){
                        count++;
                        sum--;
                    }
                    else{
                        sum++;
                    }
                    j--;
                }
                printf("%d ",count);
            }
        }
        printf("\n");
        top=-1;
        memset(stac,'\0',sizeof(stac));
    }
    return 0;
}
