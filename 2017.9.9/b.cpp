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
const int maxn 1e5+5;
char s[maxn];
char t[20];
int n;
int main(){
	freopen("test.txt","r",stdin);
	int ta;
	scanf("%d",&ta);
	while(ta--){
		scanf("%d",&n);
		scanf("%s",s);
		scanf("%s",t);
		char ch;
		int left,right;
		int pos;
		char word;
		while(n--){
			getchar();
			scanf("%c",&ch);
			printf("%c\n",ch);
			if(ch=="C"){
				scanf("%d %c",&pos,&word);
				s[pos-1]=word;
			}
			else{
				scanf("%d %d",&left,&right);
			}
		}
	}
	return 0;
}