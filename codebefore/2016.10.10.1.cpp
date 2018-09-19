#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<malloc.h>
using namespace std;
char s[1005];
int Map[105][105];
int len;
void Creat_Relative(int pre,int now,int i){
    if(i==len)
        return;
    if(s[i]>='0'&&s[i]<='9'){
        now*=10;
        now+=s[i]-'0';
        Creat_Relative(pre,now,i+1);
    }
    else if(s[i]=='('){
        if(pre!=-1)
            Creat_Relative(now,0,i+1);
        else
            Creat_Relative(pre,0,i+1);
    }
    else if(s[i]==')'){
        while(s[i+1]==')')
            i++;
        if(pre!=-1){
            printf("%d %d\n",pre,now);
            Map[pre][now]=1;
            Creat_Relative(pre,0,i+1);
        }
    }
}
int main(){
    while(~scanf("%s",s)){
        int i,j;
        len=strlen(s);
        Creat_Relative(-1,0,0);
    }
    return 0;
}
