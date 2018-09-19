#include<stdio.h>
#include<string.h>
int main(){
    char s[1001];
    int i,j,n;
    scanf("%d",&n);
    for(j=0;j<n;j++){
        scanf("%s",s);
        int len,lenm;
        len=strlen(s);
        lenm=len/2;
        int flag=1;
        for(i=0;i<lenm;i++){
            if(s[i]!=s[len-1-i]){
                flag=0;
                break;
            }
        }
        if(flag==0)
            printf("NO\n");
        else printf("YES\n");
        memset(s,'\0',sizeof(s));
    }
    return 0;
}
