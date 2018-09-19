#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<malloc.h>
using namespace std;
char a[5005];
char b[5005];
int m[2005][2005];

int main(){
    while(~scanf("%s",a)){
        scanf("%s",b);
        int len_a,len_b;
        len_a=strlen(a);
        len_b=strlen(b);
        int i,j;
        for(i=0;i<=len_a;i++)
            m[0][i]=0;
        for(i=0;i<=len_b;i++)
            m[i][0]=0;
        for(i=1;i<=len_a;i++){
            for(j=1;j<=len_b;j++){
                if(a[i-1]==b[j-1]){
                    m[i][j]=m[i-1][j-1]+1;
                }
                else if(m[i-1][j]>m[i][j-1]){
                    m[i][j]=m[i-1][j];
                }
                else{
                    m[i][j]=m[i][j-1];
                }
            }
        }
        printf("%d\n",m[len_a][len_b]);
    }
    return 0;
}





