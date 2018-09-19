#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char s[50];
int np[25];
int nq[25];

int main(){
    int test;
    scanf("%d",&test);
    int i,j;
    int n;
    while(test--){
        scanf("%d",&n);
        int t=0;
        int num=0;
        for(i=1;i<=n;i++){
            scanf("%d",&np[i]);
            t=np[i]-np[i-1];
            while(t>0){
                s[num]='(';
                num++;
                t--;
            }
            s[num]=')';
            num++;
        }
        //puts(s);
        num=0;
        int acc;
        int count=1;
        int flag;
       for(i=0;i<2*n;i++){
            if(s[i]==')'){
                count=1;
                acc=1;
                    t=i;
                while(t--){
                    if(s[t]=='('){
                        count--;
                        if(count==0)
                            t=0;
                    }
                    else if(s[t]==')'){
                        count++;
                        acc++;
                    }
                }
                nq[num]=acc;
                if(num<n-1)
                    printf("%d ",nq[num]);
                else
                    printf("%d \n",nq[num]);
                num++;
            }
       }
    }
    return 0;
}

