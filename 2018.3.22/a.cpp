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
const int maxn=100005;
using namespace std;
char s[maxn],t[maxn];
int next[maxn];
int getnext(){
	int len=strlen(t);
	next[0]=-1;
	int k=-1;
	int j=0;
	while(j<len){
		if(k==-1||t[j]==t[k]){
			++k;
			++j;
			next[j]=k;
		}
		else{
			k=next[k];
		}
	}
}
int kmp(){
	int i=0;
	int j=0;
	int slen=strlen(s);
	int tlen=strlen(t);
	int ans=0;
	while(i<slen){
		if(j==-1||s[i]==t[j]){
			i++;
			j++;
			if(j==tlen)
				j=0;
		}
		else{
			ans+=(j-next[j]);
			j=next[j];
		}
	}
}
int main(){
	freopen("test.txt","r",stdin);
	scanf("%s %s",s,t);
	getnext();
	printf("%d\n",kmp());
	return 0;
}