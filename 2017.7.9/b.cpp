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

using namespace std;
char s[100005];
int a[10];
int main(){
	int i;
	freopen("test.txt","r",stdin);
	while(~scanf("%s",s)){
		for(i=0;i<10;i++)
			a[i]=0;
		for(i=0;i<strlen(s);i++){
			if(s[i]=='i'||s[i]=='I'){
				a[0]++;
			}
			else if(s[i]=='l'||s[i]=='L'){
				a[1]++;
			}
			else if(s[i]=='o'||s[i]=='O'){
				a[2]++;
			}
			else if(s[i]=='v'||s[i]=='V'){
				a[3]++;
			}
			else if(s[i]=='e'||s[i]=='E'){
				a[4]++;
			}
			else if(s[i]=='C'||s[i]=='c'){
				a[5]++;
			}
			else if(s[i]=='s'||s[i]=='S'){
				a[6]++;
			}
		}
		int  ans=9999999;
		for(i=0;i<7;i++){
			if(i!=4){
				if(ans>a[i])
					ans=a[i];
			}
			else{
				if(ans>a[i]/2)
					ans=a[i]/2;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}