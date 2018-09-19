#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#define ll long long
#define read(a) scanf("%d",&a);
using namespace std;
struct node{
	ll st,en;
	bool operator < (const node &u)const{
		if(st!=u.st)
			return st<u.st;
		else
			return en>u.en;
	}
};
bool cmp(node u,node v){
	if(u.en!=v.en)
		return u.en>v.en;
	else
		return u.st>v.st;
}
int main(){
	freopen("test.txt","r",stdin);
	ll t;
	scanf("%lld",&t);
	while(t--){
		ll n,a,b;
		std::vector<node> v;
		node tmp;
		scanf("%lld",&n);
		for(int i=0;i<n;i++){
			scanf("%lld %lld",&a,&b);
			tmp.st=a;
			tmp.en=b-1;
			v.push_back(tmp);
		}
		sort(v.begin(),v.end(),cmp);
		printf("\n");
		for(int i=0;i<v.size();i++){
			printf("%lld %lld\n",v[i].st,v[i].en);
		}
		priority_queue<node>que;
		tmp=v[0];
		que.push(tmp);
		for(int i=1;i<v.size()-1;i++){
			tmp=que.top();
			printf("%lld\n",tmp.st);
			if(v[i].en<tmp.st){
				que.pop();
				tmp.st=v[i].st;
				que.push(tmp);
			}
			else{
				tmp=v[i];
				que.push(tmp);
			}
		}
		ll cnt=0;
		ll ans=0;
		if(v.size()>1){
			printf("111111");
			tmp=que.top();
			int sz=v.size();
			ll maxn=999999999999999;
			if(tmp.st>v[sz-1].en){
				std::vector<node> vec;
				ll len=0;
				ll num=0;
				while(tmp.st>v[sz-1].en){
					vec[++len].st=tmp.st;
					vec[len].en=tmp.en;
					//printf("111111");
					if(maxn>tmp.en-v[sz-1].st+1){
						maxn=tmp.en-v[sz-1].st+1;
						num=len;
					}
					que.pop();
					tmp=que.top();
				}
				for(int i=1;i<=len;i++){
					tmp.st=vec[i].st;
					tmp.en=vec[i].en;
					if(i!=len){
						que.push(tmp);
					}
					else{
						tmp.st=vec[sz-1].st;
						que.push(tmp);
					}
				}
			}
			else{
				tmp.st=v[sz-1].st;
				tmp.en=v[sz-1].en;
				que.push(tmp);
			}
		}
		while(!que.empty()){
			tmp=que.top();
			cnt++;
			ans+=tmp.en-tmp.st+1;
			//printf("%lld %lld\n",tmp.st,tmp.en);
			que.pop();
			//que.push(tmp);
		}

		printf("%lld %lld\n",cnt,ans);
		//printf("\n");
		v.clear();
	}
	return 0;
}