#include<stdio.h>
#include<string.h>

int main(){
    int i,j;
    int an;
    int n,m;
    while(~scanf("%d",&n)){
            m=0;an=2;
        while(an!=1){
            if(an<=n) an*=2;
            else an=(an*2-1)%(2*n);
            m++;
        }
        printf("%d\n",m+1);
    }
    return 0;
}

