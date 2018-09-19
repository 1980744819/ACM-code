#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<malloc.h>
using namespace std;

int main(){
    char s[100005];
    while(scanf("%s",s)){
        int i=0;
        while(s[i]!='\0'){
            i++;
        }
        printf("%d\n",i);
    }
    return 0;
}

