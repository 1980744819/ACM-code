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
char s[maxn];
int num[10];
int main(){
	freopen("test.txt","r",stdin);
	scanf("%s",s);
	for(int i=0;s[i]!='\0';i++){
		int a=s[i]-'0';
		num[a]++;
	}
	return 0;
}