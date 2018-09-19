#include<iostream>
#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<cmath>
#include<algorithm>
using namespace::std;
int m;
int n;
struct stu{
    int num,len,wid;
}s[10005];
bool comp(stu a,stu b){
    if(a.num!=b.num)
        return a.num<b.num;
    else if(a.num==b.num&&a.len!=b.len)
        return a.len<b.len;
    else
        return a.wid<b.wid;
}
int main(){
    while(~scanf("%d",&n)){
        int i,j;
        while(n--){
            scanf("%d",&m);
            int a,b,c;
            for(i=0;i<m;i++){
                scanf("%d %d %d",&a,&b,&c);
                s[i].num=a;
                if(b>=c){
                    s[i].len=b;
                    s[i].wid=c;
                }
                else{
                    s[i].len=c;
                    s[i].wid=b;
                }
            }
            sort(s,s+m,comp);
            cout<<s[0].num<<" "<<s[0].len<<" "<<s[0].wid<<endl;
            for(i=1;i<m;i++){
                if(s[i].num==s[i-1].num&&s[i].len==s[i-1].len&&s[i].wid==s[i-1].wid)
                    continue;
                    cout<<s[i].num<<" "<<s[i].len<<" "<<s[i].wid<<endl;
            }
        }
    }
    return 0;
}


