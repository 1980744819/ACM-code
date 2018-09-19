#include<iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<cmath>
#include<algorithm>
using namespace::std;
int m;
int n;
struct stu{
    char c[200];
    int num;
}s[10005];
bool comp(stu a,stu b){
    if(strcmp(a.c,b.c)<0)
        return true;
    else
        return false;
}
int main(){
    while(~scanf("%d",&n)){
        int i,j,k;
        char ch[100];
        int len;
        char a[200];
        m=0;
        for(i=0;i<n;i++){
            scanf("%s",ch);
            len=strlen(ch);
            k=0;
            for(j=0;j<len;j++){
                if(ch[j]<='9'&&ch[j]>='0'){
                    a[k]=ch[j];
                    k++;
                }
                else if(ch[j]=='-'){
                    continue;
                }
                else{
                    if(ch[j]=='A'||ch[j]=='B'||ch[j]=='C'){
                        a[k]='2';
                        k++;
                    }
                    else if(ch[j]=='D'||ch[j]=='E'||ch[j]=='F'){
                        a[k]='3';
                        k++;
                    }
                    else if(ch[j]=='G'||ch[j]=='H'||ch[j]=='I'){
                        a[k]='4';
                        k++;
                    }
                    else if(ch[j]=='J'||ch[j]=='K'||ch[j]=='L'){
                        a[k]='5';
                        k++;
                    }
                    else if(ch[j]=='M'||ch[j]=='N'||ch[j]=='O'){
                        a[k]='6';
                        k++;
                    }
                    else if(ch[j]=='P'||ch[j]=='R'||ch[j]=='S'){
                        a[k]='7';
                        k++;
                    }
                    else if(ch[j]=='T'||ch[j]=='U'||ch[j]=='V'){
                        a[k]='8';
                        k++;
                    }
                    else if(ch[j]=='W'||ch[j]=='X'||ch[j]=='Y'){
                        a[k]='9';
                        k++;
                    }
                    else continue;
                }
            }
            a[k]='\0';
            /*for(j=0;j<k;j++)
                printf("%c",a[j]);
            printf("\n");*/
            int flag;
            if(m==0){
                strcpy(s[m].c,a);
                s[m].num=1;
                m++;
            }
            else{
                flag=0;
                for(j=0;j<m;j++){
                    if(strcmp(s[j].c,a)==0){
                        s[j].num++;
                        flag=1;
                        //printf("1111\n");
                        break;
                    }
                }
                if(!flag){
                    strcpy(s[m].c,a);
                    s[m].num=1;
                    m++;
                    //printf("2222\n");
                }
            }
            //printf("%d\n",m);
        }
        sort(s,s+m-1,comp);
        int flag;
        flag=0;
        for(i=0;i<m;i++){
            if(s[i].num>1){
                flag=1;
                for(j=0;j<3;j++){
                    printf("%c",s[i].c[j]);
                }
                printf("-");
                for(j=3;j<7;j++){
                    printf("%c",s[i].c[j]);
                }
                printf(" %d\n",s[i].num);
            }
        }
        if(!flag)
            printf("No duplicates.\n");
    }
    return 0;
}




