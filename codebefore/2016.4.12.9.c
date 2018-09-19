#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int top=-1;
char s;
char a[100001];
int main(){
    int i;
    s=getchar();
    while(s!=EOF){
       while(s!=EOF&&s!='\n'){
            switch(s){
            case '#':top--;break;
            case '@':top=-1;break;
            default:
                top++;
                a[top]=s;
                break;
            }
       s=getchar();
       }
       int i=0;
       while(i<=top){
        printf("%c",a[i]);
        i++;
       }
       top=-1;
       printf("\n");
       if(s!=EOF){
            s=getchar();
       }
    }
    return 0;
}

