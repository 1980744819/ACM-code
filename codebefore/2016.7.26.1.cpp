#include<cstdio>
#include<string>
#include<iostream>
#include<queue>
#define INF 0x7fffffff
using namespace std;
priority_queue<int ,vector<int>,greater<int> > q;
//priority_queue<int,vector<int>,greater<int> > q;
int main(){

    int n,num,i,a,b;
    long long sum;
    while(~scanf("%d",&n)){
        for(i=1;i<=n;i++){
            scanf("%d",&num);
            q.push(num);
        }
        q.push(INF);
        sum=0;
        while(!q.empty()){
             a=q.top();q.pop();
             b=q.top();q.pop();
            if(b==INF)
                break;
            sum+=a;
            sum+=b;
            q.push(a+b);
        }
        while(!q.empty())
            q.pop();
        printf("%lld\n",sum);
    }
    return 0;
}
