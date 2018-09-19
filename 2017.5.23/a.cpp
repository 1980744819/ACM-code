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
char s[100005];
int main(){
	int i,j;
	int n;
	int ans;
	int l,l2,maxn;
	while(~scanf("%d",&n)){
		scanf("%s",s);
		ans=1;
		l=1;
		l2=0;
		maxn=0;
		for(i=0;i<n-1;i++){
			if(s[i]==s[i+1]){
				l++;
			}
			else{
				if(l==2)l2++;
				l=1;
				ans++;
			}
			maxn=max(l,maxn);
		}
		if(maxn>=3)
			ans+=2;
		if(l==2)
			l2++;
		if(l2>=2&&maxn==2)
			ans+=2;
		if(l2==1&&maxn==2)
			ans++;
		printf("%d\n",ans);
	}
    return 0;
}
