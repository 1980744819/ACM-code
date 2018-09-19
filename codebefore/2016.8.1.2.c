#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char s[7];
int ans[7];
int t[7];
int lent;
int flag;
int max;
int target;
int len;
void dfs(int i,int time,int num){
    if(num>target)
        return;
    int k;
    if(i>=len){
        if(max<num){
            max=num;
            flag=1;
            lent=time;
            for(k=0;k<time;k++){
                ans[k]=t[k];
            }
        }
        else if(max==num){
            flag=2;
        }
        //return ;
    }
    int tmp;
    int a=0;
    for(k=i;k<len;k++){
        tmp=s[k]-48;
        a*=10;
        a+=tmp;
        t[time]=a;
        dfs(k+1,time+1,a+num);
    }
}
int main(){
    while(~scanf("%d %s",&target,s)){
        //puts(s);
        if(target==0&&s[0]=='0')
            break;
        len=strlen(s);
        max=0;
        flag=0;
        lent=0;
        dfs(0,0,0);
        if(flag==0){
            printf("error\n");
        }
        else if(flag==1){
            printf("%d",max);
            int i;
            for(i=0;i<lent;i++){
                printf(" %d",ans[i]);
            }
            printf("\n");
        }
        else
            printf("rejected\n");
    }
    return 0;
}

