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
	char s1[20],s2[20];
	scanf("%s",s1);
	int len=strlen(s1);
	int coun=0;
	for(int i=0;i<len;i++){
		s2[len-1-i]=s1[i];
	}
	//puts(s2);
	for(int i=0;i<len;i++){
		if(s1[i]!=s2[i]){
			coun++;
		}
	}
	if(coun==2||(coun==0&&len%2==1))
		printf("YES\n");
	else 
		printf("NO\n");
    return 0;
}
