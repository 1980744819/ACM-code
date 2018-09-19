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
char s[200005];
int main(){
	int i,j;
	int len;
	scanf("%s",s);
	len=strlen(s);
	for(i=1;i<len-1;i++){
		if(s[i]==s[i-1]){
			for(char c='a';c<='z';c++){
				if(c!=s[i-1]&&c!=s[i+1]){
					s[i]=c;
					break;
				}
			}
		}
	}
	if(s[len-2]==s[len-1]){
		for(char c='a';c<='z';c++){
			if(c!=s[len-2]){
				s[len-1]='c';
				break;
			}
		}
	}
	puts(s);
    return 0;
}
