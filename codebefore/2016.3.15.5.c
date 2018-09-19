#include<stdio.h>
#include<string.h>
int main(){
    char str[101];
    scanf("%s",str);
    int n=strlen(str);
    printf("%d\n",n);
    int i;
    for( i=n-1;i>=0;i--)
        printf("%c",str[i]);
    printf("\n");
    return 0;
}
