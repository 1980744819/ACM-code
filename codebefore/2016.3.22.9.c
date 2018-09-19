#include<stdio.h>
#include<string.h>
int main(){
    char s[1001];
    while(~scanf("%s",s)){
        int flag=0;
        int len=strlen(s);
        int i,j;
        for(i=len-1;i>=0;i--){
            if(s[i]>='p'&&s[i]<='z')
                flag++;
            else if(s[i]=='N');
            else if(s[i]=='C'||s[i]=='D'||s[i]=='E'||s[i]=='I')
                flag--;
            else {
                flag=0;
                break;
            }
        }
        if(flag==1)
            printf("YES\n");
        else printf("NO\n");
        memset(s,'\0',sizeof(s));
    }
    return 0;
}


