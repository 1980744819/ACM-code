#include<stdio.h>
#include<stdlib.h>
int main()
{
    char str[100];
    int i,len=0;
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++)
    {
         len++;
    }
    printf("%d\n",len);
    if(str[len-1]=='0') 
        printf("EVEN\n");
    else 
        printf("ODD\n");
    return 0;
}
