#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char s[400];
int stac[1000];
int top=-1;
int put(char a,int pp,int qq,int rr,int ss,int tt){
    switch(a){
        case 'p':top++;stac[top]=pp;return 1;
        case 'q':top++;stac[top]=qq;return 1;
        case 'r':top++;stac[top]=rr;return 1;
        case 's':top++;stac[top]=ss;return 1;
        case 't':top++;stac[top]=tt;return 1;
    }
    return 0;
}
void oprand(char a){
    int x,y;
    switch(a){
        case 'K':{
            x=stac[top];
            top--;
            y=stac[top];
            stac[top]=(x&&y);
            break;
        }
        case 'A':{
            x=stac[top];
            top--;
            y=stac[top];
            stac[top]=(x||y);
            break;
        }
        case 'N':{
            x=stac[top];
            stac[top]=(!x);
            break;
        }
        case 'C':{
            x=stac[top];
            top--;
            y=stac[top];
            stac[top]=((!x)||y);
            break;
        }
        case 'E':{
            x=stac[top];
            top--;
            y=stac[top];
            stac[top]=(x==y);
            break;
        }
    }
    return;
}
int main(){
    int i,j;
    int len;
    int pp,qq,rr,ss,tt;
    int ans;
    int flag;
    while(~scanf("%s",s)){
        if(s[0]=='0')break;
        len=strlen(s);
        flag=1;
        for(pp=0;pp<=1;pp++){
            for(qq=0;qq<=1;qq++){
                for(rr=0;rr<=1;rr++){
                    for(ss=0;ss<=1;ss++){
                        for(tt=0;tt<=1;tt++){
                            for(i=len-1;i>=0;i--){
                                if(put(s[i],pp,qq,rr,ss,tt)==0){
                                    oprand(s[i]);
                                }
                            }
                            ans=stac[top];
                            if(!ans){
                                flag=0;
                                break;
                            }
                        }
                        if(!flag){
                            break;
                        }
                    }
                    if(!flag){
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        if(flag)
            printf("tautology\n");
        else printf("not\n");
        top=-1;
    }
    return 0;
}
