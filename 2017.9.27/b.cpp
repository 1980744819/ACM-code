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
const int maxn=1005;
int get_min(int a[]){
	int Mi=100;
	for(int i=1;i<=a[0];i++){
		Mi=min(Mi,a[i]);
	}
	return Mi;
}
void dfs(int a[],int cur){
	printf("a: ");
	for(int i=a[0];i>=1;i--)
		printf("%d",a[i]);
	printf("\n");
	if(a[0]==0){
		printf("min step : %d\n",cur);
		return;
	}
	else{
		int b[maxn];
		memset(b,0,sizeof(b));
		int left,right;
		int flag=0;
		if(a[1]==0){
			flag=1;
			left=1;
			a[1]-=1;
			while(a[left]<0){
				a[left]+=10;
				a[left+1]-=1;
				left++;
			}
			if(a[a[0]]==0)
				a[0]--;
		}
		left=1;
		right=a[0];
		b[0]=a[0];
		while(left<=right){
			b[left]=b[right]=min(a[left],a[right]);
			left++;
			right--;
		}
		int c[maxn];
		memset(c,0,sizeof(c));
		if(flag){
			left=1;
			a[left]+=1;
			while(a[left]>=10){
				a[left]-=10;
				a[left+1]+=1;
				left++;
			}
			if(a[a[0]+1]!=0){
				a[0]+=1;
			}
		}
		for(int i=1;i<=b[0];i++){
			if(b[i]>a[i]){
				a[i]+=10;
				a[i+1]-=1;
			}
			c[i]=a[i]-b[i];
		}
		c[0]=0;
		for(int i=a[0];i>=1;i--){
			if(c[i]!=0){
				c[0]=i;
				break;
			}
		}
		printf("b: ");
		for(int i=b[0];i>=1;i--){
			printf("%d",b[i]);
		}
		printf("\n");
		printf("c: ");
		for(int i=c[0];i>=1;i--){
			printf("%d",c[i]);
		}
		printf("\n");
		dfs(c,cur+1);
		// for(int i=b[0];i>=1;i--){
		// 	printf("%d",b[i]);
		// }
		// printf("\n");
	}
	return;
}
int main(){
	freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&t);
	int ca=1;
	while(t--){
		char s[maxn];
		scanf("%s",s);
		int len=strlen(s);
		int a[maxn];
		memset(a,0,sizeof(a));
		a[0]=len;
		for(int i=1;i<=len;i++){
			a[i]=s[len-i]-'0';
		}
		printf("Case #%d:\n",ca++);
		dfs(a,0);
		// for(int i=len;i>=0;i--)
		// 	printf("%d",a[i]);
		// printf("\n");

	}
    return 0;
}
