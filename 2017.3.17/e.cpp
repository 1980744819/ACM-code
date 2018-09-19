#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
char a[1000];
char b[1000];
bool judgea(){
    int i=0;
    int len=strlen(a);
    if(len==1){
        if(a[0]<='9'&&a[0]>='1')
            return true;
        else
            return false;
    }
    else{
        int coun=0;
        for(i=0;i<len;i++){
            if(a[i]=='0')
                coun++;
            if(a[i]<'0'||a[i]>'9')
                return false;
        }
        if(coun==len)
            return false;
    }
    return true;
}
bool judgeb(){
    int i=0;
    int len=strlen(b);
    if(len==1){
        if(b[0]<='9'&&b[0]>='1')
            return true;
        else
            return false;
    }
    else{
        int coun=0;
        for(i=0;i<len;i++){
            if(b[i]=='0')
                coun++;
            if(b[i]<'0'||b[i]>'9')
                return false;
        }
        if(coun==len)
            return false;
    }
    return true;
}
int main(){
    int i,j;
    while(~scanf("%s",a)){
        getchar();
        gets(b);
        if(judgea()&&judgeb()){
            int n1,n2;
            int lena=strlen(a);
            int lenb=strlen(b);
            n1=0,n2=0;
            for(i=0;i<lena;i++){
                n1*=10;
                n1+=a[i]-'0';
            }
            for(i=0;i<lenb;i++){
                n2*=10;
                n2+=b[i]-'0';
            }
            printf("%d + %d = %d\n",n1,n2,n1+n2);
        }
        else{
            if(!judgea())
                printf("? + ");
            else
                printf("%s + ",a);
            if(!judgeb())
                printf("? = ?\n");
            else
                printf("%s = ?\n",b);
        }
    }
    return 0;
}

