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
bool s[300005];
bool tmp[300005];
int main(){
	int i,j;
	int cnt;
	int n,k;
	int ans;
	scanf("%d %d",&n,&k);
	int num;
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		if(num==1)
			s[i]=true;
	}
	/*for(i=1;i<=n;i++){
		printf("%d ",s[i]==false?0:1);
	}
	printf("\n");*/
	int l,r;
	l=1;
	r=1;
	cnt=0;
	int L,R;
	L=1;
	R=0;
	ans=0;
	while(r<=n&&l<=n){
		while(cnt<=k&&r<=n){
			if(s[r]==false){
				if(cnt==k)
					break;
				cnt++;
			}
			r++;
		}
		if(ans<r-l){
			ans=r-l;
			L=l;
			R=r-1;
		}
		while(s[l]==true&&l<=n){
			l++;
		}
		l++;
		cnt--;
	}
	printf("%d\n",ans);
	for(i=1;i<L;i++){
		printf("%d ",s[i]==false?0:1);
	}
	for(i=L;i<=R;i++){
		printf("1 ");
	}
	for(i=R+1;i<=n;i++){
		printf("%d ",s[i]==false?0:1);
	}
	printf("\n");
    return 0;
}
