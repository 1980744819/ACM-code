#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef int Status;
//kmp算法思想：
void get_next(char s[100],int next[100])
{
    i=0;next[i]=0;
    j=-1;
    while(i<strlen(s)-1)
    {
        if(j==-1||s[i]==s[j])
        {
            i++;
            j++;
            next[j]=i;
        }
        else j=next[j];
    }
}
int index_kmp(char *m,char *s,int pos)
{
    int i=pos,j=0;
    while(i<strlen(m)-1&&j<strlen(s)-1)
    {
        if(j==-1||s[i]==m[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
}
int main()
{
    char s[100],m[100];
    int next[100];
    printf("    请输入你要操作的两个字符串，首先是模式串：\n");
    scanf("%s",m);
    printf("输入子串|\n");
    scanf("%s",s);
    printf("%d",strlen(s));
    get_next(s,next);
    for(i=0;i<strlen(s)-1;i++)
    {
        printf("%2d",next[i]);
    }
        
}
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef int Status;
//kmp算法思想：
void get_next(char s[100],int next[100])
{
    i=0;next[i]=0;
    j=-1;
    while(i<strlen(s)-1)
    {
        if(j==-1||s[i]==s[j])
        {
            i++;
            j++;
            next[j]=i;
        }
        else j=next[j];
    }
}
int index_kmp(char *m,char *s,int pos)
{
    int i=pos,j=0;
    while(i<strlen(m)-1&&j<strlen(s)-1)
    {
        if(j==-1||s[i]==m[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
}
int main()
{
    char s[100],m[100];
    int next[100];
    printf("    请输入你要操作的两个字符串，首先是模式串：\n");
    scanf("%s",m);
    printf("输入子串|\n");
    scanf("%s",s);
    printf("%d",strlen(s));
    get_next(s,next);
    for(i=0;i<strlen(s)-1;i++)
    {
        printf("%2d",next[i]);
    }
        
}
