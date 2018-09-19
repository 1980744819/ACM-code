#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char p[1001];
int next[1001];
void getnext(){
    int len=strlen(p);
    //printf("%d\n",len);
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
    while(~scanf("%s",p)){
            //puts(p);
        getnext();
        int len=strlen(p);
        //printf("%d\n",len);
        int i;
        for(i=0;i<len;i++){
            printf("%d ",next[i]+1);
        }
        printf("\n");
    }
    return 0;
}

