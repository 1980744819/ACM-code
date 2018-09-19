#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int a[100000006];
int b[4];
void get(int num){
    int i;
    int t;
    for(i=0;i<4;i++){
        t=num*b[i];
        if(a[t]==0){
            if(t<10000006){
                a[t]=1;
                //printf("%d    ",t);
                get(t);
            }
            else
                return;
        }
        else
            return;
    }
}
int main(){
    int i,j,num;
    int t;
    a[1]=1;
    b[0]=2;
    b[1]=3;
    b[2]=5;
    b[3]=7;
    int c[4];
    c[0]=2;
    c[1]=3;
    c[2]=5;
    c[3]=7;
    int flag=0;
    int k=0;
    while(1){
        for(i=0;i<4;i++){
            c[i]=c[i]*b[i];
            if(c[i]<100000006){
                k=0;
                a[c[i]]=1;
            }
            else{
                k++;
                if(k==4)
                    break;
            }
        }
        if(k==4)
            break;
    }
    int n;
    //get(1);
    while(~scanf("%d",&t)){
        while(t--){
            scanf("%d",&n);
            while(a[n]!=1){
                n++;
            }
            printf("%d\n",n);
        }
    }
    return 0;
}

