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
int n,m,x,y;

int main(){
    while(cin>>n>>m>>x>>y){
        if(n==m&&(n&1)&&x==y&&(n+1)/2==x){
            cout<<x-1<<endl;
            continue;
        }
        int ansx=min(max(x-1,n-x+1),max(x,n-x));
        if(y<ansx||m-y+1<ansx){
            ansx=max(min(y,m-y+1),n/2+(n&1));
        }
        int ansy=min(max(y-1,m-y+1),max(y,m-y));
        if(x<ansy||n-x+1<ansy){
            ansy=max(min(x,n-x+1),m/2+(m&1));
        }
        cout<<min(ansx,ansy)<<endl;
    }
    return 0;
}

