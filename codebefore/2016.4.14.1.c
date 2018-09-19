#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int a[100001];//´æ´¢·ûºÅ
char b[100001];//´æ´¢Êý×Ö
char c[100001];//ÖÐ×ªÕ»
int topc=-1;
int topab=-1;
int ji[10001];
topj=-1;
char s[100001];
int pan(int len){
    int i;
    int t;
    int acc=0,bcc=0;
    for(i=0;i<len-1;i++){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            if(s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='*'||s[i+1]=='/')
                return 1;
        }
        else if(s[i]==')'){
            if(s[i+1]=='(')
                return 1;
        }
        else if(s[i]=='('){
            if(s[i+1]==')')
                return 1;
        }
    }
    if(s[len-1]=='+'||s[len-1]=='-'||s[len-1]=='*'||s[len-1]=='/')
        return 1;
    for(i=len-1;i>=0;i--){
        if(s[i]==')')
            bcc++;
        else if(s[i]=='(')
                    acc++;
    }
    if(acc!=bcc){
        return 1;
    }
    char pei[10001];
    int toppei=-1;
    i=0;
    while(i<len){
        if(s[i]=='('){
            toppei++;
            pei[toppei]=s[i];
            i++;
        }
        else if(s[i]==')'&&toppei>=0){
            toppei--;
            i++;
        }
        else if(s[i]==')'&&toppei==-1)
            return 1;
        else
            i++;
    }
    if(toppei!=-1)
        return 1;
    return 0;
}
int main(){
    int num=0;
    int flag=0;
    while(~scanf("%s",s)){
            int len=strlen(s);
            int i,j;
            for(i=0;i<len;i++)
                a[i]=9999;
            //for(i=0;i<10;i++)
                //printf("%d\n",a[i]);
            flag=pan(len);
            //printf("%d",flag);
            i=0;
            while(i<len&&flag!=1){
                if(isdigit(s[i])==1){
                    while(isdigit(s[i])==1){
                        num*=10;
                        num+=s[i]-48;
                        i++;
                    }
                    topab++;
                    a[topab]=num;
                    num=0;
                }
                else if(s[i]=='('){
                    topc++;
                    c[topc]=s[i];
                    i++;
                }
                else if(s[i]==')'){
                    while(c[topc]!='('&&topc>=0){
                            topab++;
                            b[topab]=c[topc];//printf("%c\n",b[topab]);
                            topc--;
                            if(topc==-1){flag=1;break;}
                          }
                          topc--;
                          i++;
                }
                else{
                    if(s[i]=='-'){
                        if(i==0){
                            flag=1;
                            break;
                        }
                        else{
                            if(s[i-1]=='('){
                                flag=1;
                                break;
                            }
                            else{
                                while(c[topc]!='('&&topc>=0){
                                    topab++;
                                    b[topab]=c[topc];//printf("%c\n",b[topab]);
                                    topc--;
                                    if(topc==-1)
                                        break;
                                }
                                topc++;
                                c[topc]=s[i];
                                i++;
                            }
                        }
                    }
                    else if(s[i]=='+'){
                        while(c[topc]!='('&&topc>=0){
                            topab++;
                            b[topab]=c[topc];//printf("%c\n",b[topab]);
                            topc--;
                            if(topc==-1)
                                break;
                        }
                        topc++;
                        c[topc]=s[i];
                        i++;
                    }
                    else if(s[i]=='*'||s[i]=='/'){
                        while((c[topc]=='*'||c[topc]=='/')&&topc>=0){
                            topab++;
                            b[topab]=c[topc];//printf("%c\n",b[topab]);
                            topc--;
                            if(topc==-1)
                                break;
                        }
                        topc++;
                        c[topc]=s[i];
                        i++;
                    }
                }
            }
            while(topc>=0){
                topab++;
                b[topab]=c[topc];//printf("%c\n",b[topab]);
                topc--;
            }
        /*for(i=0;i<=topab;i++){
            if(a[i]!=9999)
                printf("%d\n",a[i]);
            else
                printf("%c\n",b[i]);
        }*/
        for(i=0;i<=topab;i++){
            if(a[i]!=9999){
                topj++;
                ji[topj]=a[i];
            }
            else{
                if(topj-1>=0){
                    switch(b[i]){
                        case '+':ji[topj-1]=ji[topj-1]+ji[topj];topj--;break;
                        case '-':ji[topj-1]=ji[topj-1]-ji[topj];topj--;break;
                        case '*':ji[topj-1]=ji[topj-1]*ji[topj];topj--;break;
                        case '/':if(ji[topj]!=0){
                                    ji[topj-1]=ji[topj-1]/ji[topj];
                                    topj--;
                                }
                                else{
                                    flag=1;
                                }
                                break;
                        default:break;
                    }
                }
                else{flag=1;break;}
            }
        }
        if(flag==0){
            if(ji[0]>=0)
                printf("%d\n",ji[0]);
            else
                printf("error\n");
        }
        else{
            printf("error\n");
        }
        flag=0;
        topab=-1;
        topj=-1;
    }
    return 0;
}
