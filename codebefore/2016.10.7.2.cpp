#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main(){
    char s[105];
    int len,i,j;
    for(i=1;i<=101;i++){
        len=rand()%101;
        for(j=0;j<len;j++){
            if(rand()%2==0)
                s[j]='A';
            else
                s[j]='B';
        }
        s[len]='\0';
        puts(s);
    }
    return 0;
}


