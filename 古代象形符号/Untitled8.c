#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s[1005];
    int n=0;
    int len=0;
    int k=0;
    int i,j;
    double ans;
    gets(s);
    len=strlen(s);
    for(i=0;i<len;i++){
        if(s[i]==' '){
            k++;
            if(s[i-1]!=' '){
                n++;
            }
        }
    }
    if(s[len-1]!=' '){
        n++;
    }
    ans=(len-k);
    ans=ans*1.00;
    ans/=n;
    printf("%.2lf\n",ans);
    return 0;
}
