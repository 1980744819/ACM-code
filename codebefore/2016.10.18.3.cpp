#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<malloc.h>
using namespace std;
int num[100005];
int pre[100005];
int las[100005];
int len;
int lenpre,lenlas;
void add(){
    len=lenlas;
    int i;
    for(i=0;i<=lenlas;i++){
        las[i]+=pre[i];
        if(las[i]>=10){
            las[i]%=10;
            if(las[i+1]=='\0'){
                las[i+1]=1;
                las[i+2]='\0';
                lenlas++;
            }
            else{
                las[i+1]++;
            }
        }
    }
}
void fb(int n){
    int i=0;
    int j;
    while(i!=n){
        if(i==1){
            las[0]=1;
            las[1]='\0';
        }
        else if(i==2){
            las[0]=1;
            las[1]='\0';
            pre[0]=1;
            pre[1]='\0';
        }
        else{
            for(j=0;j<lenlas;j++){
                num[j]=las[j];
            }
            add();
            for(j=0;j<len;j++){
                pre[j]=num[j];
            }
            pre[len]='\0';
        }
        i++;
    }
        for(j=lenlas-1;j>=0;j--)
            printf("%d",las[j]);
        printf("\n");
        return;
}
int main(){
    int n;
    while(scanf("%d",&n)&&n!=0){
        //len=0;
        lenpre=1;
        lenlas=1;
        memset(num,'\0',sizeof(num));
        memset(pre,'\0',sizeof(pre));
        memset(las,'\0',sizeof(las));
        fb(n+1);
    }
    return 0;
}


