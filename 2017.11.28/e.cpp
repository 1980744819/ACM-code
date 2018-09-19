#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=50010;
char str1[MAXN];
char str2[MAXN];

int next[MAXN];
int ex[MAXN];
void getNext(char *p)
{
    int j,k;
    j=0;
    k=-1;
    int len=strlen(p);
    next[0]=-1;
    while(j<len)
    {
        if(k==-1||p[j]==p[k])
        {
            j++;
            k++;
            next[j]=k;
        }
        else k=next[k];
    }
}

void get_ex(char *p,char *q)
{
    int len1=strlen(p);
    int len2=strlen(q);
    getNext(p);
    int i,k;
    ex[0]=0;
    i=0;
    k=0;
    while(i<len2)
    {
        if(k==-1||p[k]==q[i])
        {
            i++;
            k++;
            ex[i]=k;
        }
        else k=next[k];
    }
}
int main()
{
    while(scanf("%s%s",&str1,&str2)!=EOF)
    {
        get_ex(str1,str2);
        int n=strlen(str2);
        if(ex[n]==0)printf("0\n");
        else
        {
            for(int i=0;i<ex[n];i++)printf("%c",str1[i]);
            printf(" %d\n",ex[n]);
        }
    }
    return 0;
}
