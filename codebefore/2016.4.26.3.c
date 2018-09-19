#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int next[100];
char s[100];
char p[100];
void getnext(){
    int len=strlen(p);
    next[0]=-1;
    int k=-1;
    int j=0;
    while(j<len-1){
        if(k==-1||p[k]==p[j]){
            ++k;
            ++j;
            next[j]=k;
        }
        else{
            k=next[k];
        }
    }
}
int main(){
    while(~scanf("%s %s",s,p)){
        int i=0;
        int j=0;
        int slen=strlen(s);
        int plen=strlen(p);
        while(i<slen&&j<plen){
            if(s[i]==p[j]){
                printf("%c",s[i]);
                i++;
                j++;
            }
            else{
                printf("%c",s[i]);
                i=i-j+1;
                j=0;
            }
        }
        printf("\n");
        if(j==plen)
            printf("%d\n",i-j+1);
        else
            printf("0\n");
    }
    return 0;
}

