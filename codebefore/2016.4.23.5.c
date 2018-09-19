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
    while(~scanf("%s",s)){
        //getchar();
        scanf("%s",p);
        //getchar();
        int i=0;
        int j=0;
        int slen=strlen(s);
        int plen=strlen(p);
        int num=0;
        getnext();
        while(i<slen&&j<plen){
            if(j==-1||s[i]==p[j]){
                i++;
                j++;
            }
            else{
                j=next[j];
            }
        }
        //printf("%d\n",j);
        int k;
        if(j==plen){
            /*int nu;
                nu=i-j;
            k=0;
            while(k<i){
                printf("%c",s[k]);
                k++;
            }*/
            printf("%d\n",i-j+1);
        }
        else{
            /*k=0;
            while(k<slen){
                printf("%c",s[k]);
                k++;
            }*/
            printf("0\n");
        }
    }
    return 0;
}

