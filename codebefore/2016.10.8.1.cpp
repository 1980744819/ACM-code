#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace::std;
struct stu{
    int x,y;
    int s,t;
}que[10000001];
int book[1000][1000];
int main(){
    int head,tail;
    int k;
    while(~scanf("%d",&k)){
        while(k--){
            head=0;
            tail=0;
            int a,b,c,d;
            scanf("%d %d %d %d",&a,&b,&c,&d);
            que[head].x=a;
            que[head].y=b;
            que[head].s=a;
            que[head].y=b;
            if(a<0){
                a=0-a;
                a*=2;
            }
            if(b<0){
                b=0-b;
                b*=2;
            }
            book[a][b]=1;
            tail++;
            int i,j;
            while(head!=tail){
                for(i=1;i<=8;i++){
                    switch(i){
                        case 1:break;
                    }
                }
            }
        }
    }
    return 0;
}
