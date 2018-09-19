#include<stdio.h>
#include<stdlib.h>
int sumxy(char str[100]){
    int i,c=0;
    gets(str);
    for(i=0;str[i]!='\0';i++){
        if(str[i]>='a'&&str[i]<='z')
            c=c+1;
     }
    return c;
}
int main(){
    char str[100];
    int i,c;
    c=sumxy(str);
    printf("%d",c);
    return 0;
}