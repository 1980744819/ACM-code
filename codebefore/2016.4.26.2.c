#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char a[200];
char b[200];
int main(){
    int n;
    int i,j;
    while(~scanf("%s",a)){
            getchar();
        scanf("%s",b);
        //puts(b);
        scanf(" %d",&n);
        //printf("%d\n",n);
        j=0;
        i=0;
        for(i=0;i<n-1;i++){
            printf("%c",a[i]);
        }
        int lena=strlen(a);
        int lenb=strlen(b);
        while(j<lenb){
            printf("%c",b[j]);
            j++;
        }
        while(i<lena){
            printf("%c",a[i]);
            i++;
        }
        printf("\n");
        //memset(a,'\n',sizeof(a));
    }
    return 0;
}

