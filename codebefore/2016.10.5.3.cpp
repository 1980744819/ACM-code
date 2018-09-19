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
    for(i=1;i<=1000;i++){
        number=rand()%100;
        n=rand()%30;
        char c;
        printf("%d ",i);
        for(j=n;j>=0;j--){
            c=rand()%126;
            if(c<33)
                c+=33;
            printf("%c",c);
        }
        printf(" %d\n",number);
    }
    while(1);
    return 0;
}
