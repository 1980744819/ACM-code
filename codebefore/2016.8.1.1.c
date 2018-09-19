#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int target;
char s[10];
int a[10];
int co[10];
int lens;
int flag;
int max;
int n;
void dfs(int i,int dep,int num){
    int k;
    //a[dep]=num;
    if(i==lens-1){
        if(max<num){
            max=num;
            n=dep;
            flag=0;
            for(k=0;k<=n;k++){
                co[k]=a[k];
            }
        }
        else if(max==num){
            flag=1;
            n=0;
        }
        return;
    }
    int b=0;
    int t=0;
    for(k=i+1;k<lens;k++){
        t=s[i]-48;
        b*=10;
        b+=t;
        if(num+b<=target){
            a[dep+1]=b;
            dfs(k,dep+1,num+b);
        }
    }
}
int main(){
    while(~scanf("%d",&target)){
        getchar();
        scanf("%s",s);
        //puts(s);
        if(target==0&&s[0]=='0')
            break;
         lens=strlen(s);
         int i,j;
         int num=0;
         int t;
         max=0;
         for(i=0;i<lens;i++){
            t=s[i]-48;
            num*=10;
            num+=t;
            a[0]=num;
            dfs(i,0,num);
         }
         if(flag==0){
            printf("%d",max);
            for(i=0;i<=n;i++)
                printf(" %d",co[i]);
            printf("\n");
         }
    }
    return 0;
}
