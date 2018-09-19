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
ll s[105];
ll len=0;
void change(ll num,ll ba){
	len=0;
	while(num){
		ll tmp=num%ba;
		s[++len]=tmp;
		num/=ba;
	}
	// for(ll i=len;i>=1;i--){
	// 	printf("%lld ",s[i]);
	// }
	// printf("\n");
	// printf("%lld\n",len);
}
ll dfs(ll left,ll right,ll num,ll ba,ll cur){
	if(left>right)
		return 0;
	ll i,j;
	i=left;
	j=right;
	ll temp;
	ll ans=0;
	if(cur==0){
		temp=s[j]-1;
	}
	else{
		temp=s[j];
	}
	if(temp>0){
		i++;
		j--;
		while(i<=j){
			temp*=ba;
			i++;
			j--;
		}
		ans+=temp;
	}
	if(left==right){
		ans++;
	}
	else if(s[left]>=s[right]&&left+1==right){
		ans++;
	}
	// for(ll p=1;p<=len;p++)
	// 	printf("%lld\n",s[p]);
	// printf("\n");
	ll tmp=pow(ba,right-left);
	tmp=num%tmp;
	tmp/=ba;
	//printf("%lld %lld %lld %lld\n",s[right],s[left],ans,tmp);
	//printf("%lld %lld\n",num,tmp);
	if(s[left]<s[right]){
		tmp--;
		if(tmp>=0){
			ll a=s[right]-s[left];
			ll k=left;
			s[k]=s[right];
			k++;
			s[k]--;
			while(s[k]<0){
				s[k]+=ba;
				s[k+1]--;
				k++;
			}
		}
	}
	if(tmp<0){
		return ans;
	}
	else{
		return ans+dfs(left+1,right-1,tmp,ba,cur+1);
	}
}
ll solve(ll num,ll ba){
	ll ans=1;
	for(ll i=1;i<len;i++){
		ll tmp=i;
		ll temp=ba-1;
		tmp-=2;
		while(tmp>0){
			temp*=ba;
			tmp-=2;
		}
		ans+=temp;
	}
	//printf("%lld\n",ans);
	ans+=dfs(1,len,num,ba,0);
	//printf("%lld\n",ans);
	return ans;
}
// ll dfs(ll left,ll right,ll num,ll ba){
// 	if(left>right)
// 		return 0;
// 	ll i=left,j=right;
// 	ll ans=0;
// 	ll temp=a[j]-1;
// 	while(temp>0){
// 		i++;
// 		j--;

// 	}
// }
int main(){
	freopen("test.txt","r",stdin);
	// change(496690840,12);
	// printf("%lld\n",solve(496690840,12));
	// for(ll i=2;i<=36;i++){
	// 	for(ll j=100000000;j<=1000000000;j++){

	// 	}
	// }
	ll t;
	scanf("%lld",&t);
	ll ans;
	ll ca=1;
	while(t--){
		ll L,R,l,r;
		ans=0;
		scanf("%lld %lld %lld %lld",&L,&R,&l,&r);
		for(ll i=l;i<=r;i++){
			change(R,i);
			ll ans1=solve(R,i);
			change(L-1,i);
			ll ans2=solve(L-1,i);
			ans+=(ans1-ans2)*(i-1);
			//ans=1980*9;
			printf("%lld %lld %lld %lld %lld %lld\n",L,R,i,ans1,ans2,ans1-ans2);
		}
		ans+=(R-L+1)*(r-l+1);
		printf("Case #%lld: %lld\n",ca++,ans);
	}
	return 0;
}