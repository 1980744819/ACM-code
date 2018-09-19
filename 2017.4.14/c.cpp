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
int main(){
	char s[100005];
	int i,j;
	int len;
	scanf("%s",s);
		for(i=0;s[i]!='\0';i++){
			if(s[i]>'a'){
				//s[i]--;
				break;
			}
		}
		if(s[i]=='\0'){
			s[i-1]='z';
		}
		while(s[i]!='\0'){
			if(s[i]=='a'){
				break;
			}
			else{
				s[i]--;
				i++;
			}
		}
		puts(s);
    return 0;
}
