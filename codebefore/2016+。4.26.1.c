#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char a[301];
char b[101];
int main(){
    while(~scanf("%s",a)){
        getchar();
        scanf("%s",b);
        int lena=strlen(a);
        int lenb=strlen(b);
        if(lena+lenb>100)
            printf("Result String is cutted.\n");
        else{
            strcat(a,b);
            puts(a);
        }
    }
    return 0;
}
