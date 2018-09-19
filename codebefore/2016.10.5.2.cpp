#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace::std;

int main(){
    int i,j;
    int number;
    char nam[30];
    int n;
    int op;
    for(i=1;i<=100;i++){
        op=rand()%2;
        if(op==1)
            printf("borrow ");
        else
            printf("return ");
        number=rand()%1000;
        n=rand()%30;
        char c;
        printf("%d ",number);
        for(j=n;j>=0;j--){
            c=rand()%126;
            if(c<33)
                c+=33;
            printf("%c",c);
        }
        printf("\n");
    }
    while(1);
    return 0;
}

