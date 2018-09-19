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
    int t;
    int m,n;
    int a[10005],b[10005];
    int i,j,k;
    priority_queue<int>q;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&m,&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        m--;
        while(m--){
            for(i=0;i<n;i++){
                scanf("%d",&b[i]);
            }
            sort(b,b+n);
            for(i=0;i<n;i++){
                q.push(a[i]+b[0]);
            }
            int tmp;
            for(i=1;i<n;i++){
                for(j=0;j<n;j++){
                    tmp=b[i]+a[j];
                    if(tmp<q.top()){
                        q.pop();
                        q.push(tmp);
                    }
                    else{
                        break;
                    }
                }
            }
            for(i=0;i<n;i++){
                a[i]=q.top();
                q.pop();
            }
            sort(a,a+n);
        }
        for(i=0;i<n;i++){
            printf("%d",a[i]);
            if(i!=n-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
