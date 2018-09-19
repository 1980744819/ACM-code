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
#define read(a) scanf("%lld",&a);
using namespace std;
struct node{
	ll st,en;
	bool operator < (const node &u)const{
		if(en!=u.en)
			return en>u.en;
		else
			return st<u.st;
	}
}Node[100005];
struct stu{
	ll st,en;
};
bool cmp(stu p,stu q){
	if(p.st!=q.st)
		return p.st<q.st;
	else
		return p.en<q.en;
}
// bool cmp1(node p,node q){
// 	if(q.en!=p.en)
// 		return p.en<q.en;
// 	else
// 		return p.st>q.st;
// }

int main(){
	freopen("test.txt","r",stdin);
	ll t;
	scanf("%lld",&t);
	std::vector<stu> v;
	struct node tmp;
	struct stu temp;
	while(t--){
		ll n;
		scanf("%lld",&n);
		ll a,b;
		for(ll i=0;i<n;i++){
			scanf("%lld %lld",&a,&b);
			temp.st=a;
			temp.en=b-1;
			v.push_back(temp);
		}
		// printf("\n");
		// for(ll i=0;i<v.size();i++){
		// 	printf("%lld %lld\n",v[i].st,v[i].en);
		// }
		sort(v.begin(),v.end(),cmp);
		printf("\n");
		for(ll i=0;i<v.size();i++){
			printf("%lld %lld\n",v[i].st,v[i].en);
		}
		priority_queue<node> que;
		tmp.st=v[0].st;
		tmp.en=v[0].en;
		que.push(tmp);
		std::vector<node> ve;
		for(ll i=1;i<v.size();i++){
			tmp=que.top();
			if(v[i].st>tmp.en){
				tmp.en=v[i].en;
				que.pop();
				que.push(tmp);
			}
			else{
				tmp.st=v[i].st;
				tmp.en=v[i].en;
				que.push(tmp);
			}
			//printf("%lld %lld\n",tmp.st,tmp.en);
			// if(tmp.en<v[i].st){
			// 	int len=0;
			// 	int maxn=0;
			// 	int num=0;
			// 	//printf("num%d\n",num);
			// 	while(v[i].st>tmp.en){
			// 		Node[++len].st=tmp.st;
			// 		Node[len].en=tmp.en;
			// 		//printf("11111\n");
			// 		if(maxn<tmp.st){
			// 			maxn=tmp.st;
			// 			num=len;
			// 		}
			// 		que.pop();
			// 		tmp=que.top();
			// 	}
			// 	for(int j=1;j<=len;j++){
			// 		tmp=Node[j];
			// 		if(j!=num){
			// 			que.push(tmp);
			// 		}
			// 		else{
			// 			tmp.en=v[i].en;
			// 			que.push(tmp);
			// 		}
			// 	}
			// }
			// else{
			// 	tmp=v[i];
			// 	que.push(tmp);
			// }

		}
		ll cnt=0;
		ll ans=0;
		while(!que.empty()){
			tmp=que.top();
			cnt++;
			ans+=tmp.en-tmp.st+1;
			//printf("%lld %lld\n",tmp.st,tmp.en);
			que.pop();
		}
		printf("%lld %lld\n",cnt,ans);
		//printf("\n");
		v.clear();
	}
	return 0;
}