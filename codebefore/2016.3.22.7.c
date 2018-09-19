#include<stdio.h>
#include<string.h>
int main(){
    char s[1001];
    gets(s);
    int len=strlen(s);
    int i;
    int flag=0;
    for(i=1;i<len;i++){
        if(s[i]==s[i-1]){
                flag=1;
            printf("%c\n",s[i]);
            break;
        }
    }
    if(!flag)
        printf("No\n");
    return 0;
}


