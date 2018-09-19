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
const int maxn=1000005;
char s[maxn];
int main(){
	freopen("test.txt","r",stdin);
	// freopen("test.out","w",stdout);
	gets(s);
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='A'&&s[i]<='Z'){
			int tmp=s[i]-'A';
			tmp++;
			tmp%=26;
			s[i]='A'+tmp;

		}
		else if(s[i]>='a'&&s[i]<='z'){
			int tmp=s[i]-'a';
			tmp++;
			tmp%=26;
			s[i]='a'+tmp;
		}
	}
	// printf("%s\n",s);
	puts(s);
    return 0;
}
