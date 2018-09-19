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

int main(){
    int a[30005],u;
    int i,j;
    int m,n;
    int k;
    int coun;
    int put;
    int tmp;
    priority_queue<int>q1;
    priority_queue<int,vector<int>,greater<int> >q2;
    while(~scanf("%d %d",&m,&n)){
        for(i=0;i<m;i++){
            scanf("%d",&a[i]);
        }
        k=0;
        for(i=1;i<=n;i++){
            scanf("%d",&u);
            for(;k<u;k++){
                q2.push(a[k]);
                if(!q1.empty()&&q1.top()>q2.top()){
                    tmp=q1.top();
                    q1.pop();
                    q1.push(q2.top());
                    q2.pop();
                    q2.push(tmp);
                }
            }
            tmp=q2.top();
            q2.pop();
            q1.push(tmp);
            printf("%d\n",q1.top());
        }
    }
    return 0;
}

