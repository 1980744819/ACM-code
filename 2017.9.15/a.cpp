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
#define ll long long
using namespace std;
const int maxn=5000005;
struct node{
    ll num;
    bool book;
}nod[maxn];
ll ab(ll u){
    if(u<0)
        return 0-u;
    else
        return u;
}
bool cmp(node u,node v){
    return ab(u.num)<ab(v.num);
}
bool cmp1(node u,node v){
    return u.num<v.num;
}
int main(){
	freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&t);
	int ca=0;
	while(t--){
	    //printf("%d\n",t);
        ll n,a,b;
        scanf("%lld %lld %lld",&n,&a,&b);
        for(ll i=0;i<n;i++){
            //scanf("%d",&num[i]);
            //'num1[i]=num[i];
            scanf("%lld",&nod[i].num);
            nod[i].book=false;
        }
        ll ans=0;
        sort(nod,nod+n,cmp);
        if(a<=0){
            ans+=a*nod[0].num*nod[0].num;
            nod[0].book=true;
        }
        else{
            ans+=a*nod[n-1].num*nod[n-1].num;
            nod[n-1].book=true;
        }
        sort(nod,nod+n,cmp1);
        if(b<=0){
            if(nod[0].book){
                ans+=b*nod[1].num;
            }
            else{
                ans+=b*nod[0].num;
            }
        }
        else{
            if(nod[n-1].book){
                ans+=b*nod[n-2].num;
            }
            else{
                ans+=b*nod[n-1].num;
            }
        }
        printf("Case #%d: %lld\n",++ca,ans);
	}
    return 0;
}

