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
	int len;
	int i,j;
	int ans;
	scanf("%s",s);
	len=strlen(s);
	char c;
	int num;
	ans=0;
	for(i=0;i<len;i++){
		c=s[i];
		//printf("%c",c);
		if(c>='0'&&c<='9'){
			num=c-'0';
		}
		else if(c>='A'&&c<='Z'){
			num=c-'A'+10;
		}
		else if(c>='a'&&c<='z'){
			num=c-'a'+36;
		}
		else if(c=='-'){
			num=62;
		}
		else{
			num=63;
		}
		//printf("%d ",num);
		int t=6;
		while(t--){
			if(num%2==0){
				ans++;
			}
			num>>=1;
		}
		//printf("%d\n",ans);
	}
	long long re=1;
	long long a=3;
	//printf("%d\n",ans);
	while(ans!=0){
		if(ans%2==1){
			re=re*a%1000000007;
		}
		ans/=2;
		a=a*a%1000000007;
	}
	printf("%lld\n",re);
    return 0;
}
