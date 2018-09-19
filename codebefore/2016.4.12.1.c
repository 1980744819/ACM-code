#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char s[15000];
int count(int a){
    int sum=1;
    int ans=0;
    while(a--){
        if(s[a]=='('){
            sum--;
            ans++;
            if(sum==0)
                return ans;
        }
        else if(s[a]==')'){
            sum++;
        }
    }
}
int main(){
    int i=0;
    int len;
    int sum;
    while(~scanf("%s",s)){
        len=strlen(s);
        for(i=0;i<len;i++){
            if(s[i]==')'){
                sum=count(i);
                printf("%d ",sum);
            }
        }
        printf("\n");
    }
    return 0;
}

