#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

int head=1;
char s[100001];
int a[100001];
int top=-1;
int main(){
    while(scanf("%s",s)!=EOF){
        head=1;
        top=-1;
        int len=strlen(s);
        int i,j;
        for(i=0;i<len;i++){
            if(s[i]=='P'){
                top++;
                a[top]=head;
                head++;
            }
            else if(s[i]=='Q'){
                    if(top>=0){
                    printf("%d ",a[top]);
                    a[top]=0;
                    top--;
                }
                else{
                    printf("error");
                    break;
                }
            }
        }
        printf("\n");
        memset(s,'\0',sizeof(s));
        memset(a,0,sizeof(a));
    }
    return 0;
}

