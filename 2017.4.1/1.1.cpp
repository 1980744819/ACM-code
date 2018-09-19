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
    map<int,int>mp;
    int t;
    int n;
    int i,j;
    int num;
    scanf("%d",&t);
    //printf("%d\n",t);
    int ans;
    while(t--){
        scanf("%d",&n);
        ans=1;
        for(i=0;i<n;i++){
            scanf("%d",&num);
            if(mp[num]>0){
                ans++;
                mp.clear();
            }
            mp[num]=1;
        }
        printf("%d\n",ans);
        mp.clear();
    }
    return 0;
}

