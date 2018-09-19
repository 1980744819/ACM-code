#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<ctype.h>

int a[10001];//后缀表达式计算
int top1;
char s[10001];//中缀转后缀
int top2;
char ch[10001];
char zh[10001];
int flag=0;
int cul(char k){
    int ans;
    switch(k){
        case '+':ans=a[top1-1]+a[top1];top1--;return ans;
        case '-':ans=a[top1-1]-a[top1];top1--;return ans;
        case '*':ans=a[top1-1]*a[top1];top1--;return ans;
        case '/':
            if(a[top1]==0){
                flag=-1;
                return -1;
            }
            else{
                ans=a[top1-1]/a[top1];top1--;return ans;
            }
    }
}
int charge(int l){
    int i=1;
    while(i<l){
        if(ch[i-1]=='+'||ch[i-1]=='-'||ch[i-1]=='*'||ch[i-1]=='/'){
            if(ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/')
                return -1;
            else if(ch[i]==')'||ch[i]=='('){
                if(ch[i+1]=='+'||ch[i+1]=='*'||ch[i+1]=='/')
                    return -1;
            }
        }
        i++;
    }
    return 0;
}
int main(){
    int i,j;
    int num=0;
    int ans=0;
    while(~scanf("%s",ch)){
        ans=0;
        top1=-1;
        top2=-1;
        i=0;
        int len=strlen(ch);
        flag=charge(len);
        if(ch[i]=='-'&&isdigit(ch[i+1])==1){
                i++;
                num=ch[i]-48;
                i++;
                while(isdigit(ch[i])==1){
                    num*=10;
                    num+=(ch[i]-48);
                    i++;
                }
                top1++;
                a[top1]=0-num;
//printf("%d %d\n",a[top1],top1);
                num=0;
            }
        while(i<len){
             if(ch[i+1]=='-'&&isdigit(ch[i+2])==1&&ch[i]=='('){
                i++;
                i++;
                num=ch[i]-48;
                i++;
                while(isdigit(ch[i])==1){
                    num*=10;
                    num+=(ch[i]-48);
                    i++;
                }
                i++;
                top1++;
                a[top1]=0-num;
                //printf("%d %d\n",a[top1],top1);
                num=0;
            }
            else if(isdigit(ch[i])==1){
                num=ch[i]-48;
                i++;
                while(isdigit(ch[i])==1){
                    num*=10;
                    num+=(ch[i]-48);
                    i++;
                }
                top1++;
                a[top1]=num;
                //printf("%d %d\n",a[top1],top1);
                num=0;
            }
            else{
                if(top2==-1){
                    top2++;
                    s[top2]=ch[i];
                    i++;
                }
                else{
                    if(ch[i]==')'){
                        while(s[top2]!='('){
                                int n=cul(s[top2]);
                                a[top1]=n;
                                top2--;
                        }
                        top2--;
                    }
                    else if(ch[i]=='+'||ch[i]=='-'){
                        if(s[top2]=='*'||s[top2]=='/'){
                            int n=cul(s[top2]);
                                a[top1]=n;
                                top2--;
                        }
                        else{
                            top2++;
                            s[top2]=ch[i];
                        }
                    }
                    else{
                        top2++;
                        s[top2]=ch[i];
                    }
                    i++;
                }
            }
        }
        if(flag!=-1){
            while(top2>=0){
                int n=cul(s[top2]);
                a[top1]=n;
                top2--;
            }
            if(flag!=-1&&a[top1]>0)
            printf("%d\n",a[top1]);
            else
                printf("error\n");
        }
        else{
                printf("error\n");
        }
        flag=0;
        memset(ch,'\0',sizeof(ch));
    }
    return 0;
}

