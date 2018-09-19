#include<stdio.h>
#include<string.h>
int main(){
    int i,j;
    int n,k;
    int sum;
    scanf("%d",&n);
    while(n--){
            scanf("%d",&k);
            if(k<0)
                k=-k;
            sum=0;
        for(i=1;;i++){
            sum+=i;
            if(sum>=k&&(sum-k)%2==0){
                printf("%d\n\n",i);
                break;
            }
        }
    }
    return 0;
}

