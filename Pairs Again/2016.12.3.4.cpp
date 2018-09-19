#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int book[100005];
int num[100005];
int main(){
    int i,j;
    int n,k;
    int ans;
    while(~scanf("%d %d",&n,&k)){
        memset(book,0,sizeof(book));
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
            book[num[i]]++;
        }
        ans=0;
        sort(num,num+n);
        int Max=num[n-1];
        for(i=0;i<n;i++){
            if(num[i]+k>Max)
                break;
            if(book[num[i]]!=0&&book[num[i]+k]!=0)
                ans+=book[num[i]+k];
        }
        printf("%d\n",ans);
    }
    return 0;
}

