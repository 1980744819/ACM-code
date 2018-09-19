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
int a[200005],col[200005],b[200005];
vector<int> ve[200005];
int find(int num){
    if(num==a[num])
        return num;
    else return a[num]=find(a[num]);
}
void insert(int l,int r){
    a[find(l)]=find(r);
}
int main(){
    int n,m,k;
    int i,j;
    int ans;
    set<int>st;
    scanf("%d %d %d",&n,&m,&k);
    int len;
    map<int,int>mp;
    int maxn;
    int l,r;
    for(i=1;i<=n;i++)
        a[i]=i;
    for(i=1;i<=n;i++){
        scanf("%d",&col[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%d %d",&l,&r);
        insert(l,r);
    }
    len=0;
    for(i=1;i<=n;i++){
        if(find(i)==i){
            b[i]=len;
            len++;
        }
    }
    for(i=1;i<=n;i++){
        ve[b[find(i)]].push_back(col[i]);
    }
    ans=0;
    for(i=0;i<len;i++){
        maxn=0;
        for(j=0;j<ve[i].size();j++){
            mp[ve[i][j]]++;
            if(maxn<mp[ve[i][j]])
                maxn=mp[ve[i][j]];
        }
        ans+=ve[i].size()-maxn;
        mp.clear();
    }
    printf("%d\n",ans);
    return 0;
}

