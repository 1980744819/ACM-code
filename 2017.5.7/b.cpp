#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s[105],t[105];
    int i=0,j=0,k=3;
    int len_s,len_t;
    while(k--){
        scanf("%s %s",s,t);
        len_s=strlen(s);
        len_t=strlen(t);
        while(i<len_s&&j<len_t){
            if(s[i]==t[j]){
                printf("%c",s[i]);
                i++;
                j++;
            }
            else{
                i=i-j+1;
                j=0;
            }
        }
        printf("\n");
        printf("%d\n",i-len_t+1);
        i=j=0;
        memset(s,'\0',105);
        memset(t,'\0',105);
    }
    return 0;
}
