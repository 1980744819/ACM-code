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
const int maxn=1e5+5;
using namespace std;
char s[1005][1005];
char str[1005];
char tm[1005];
int main(){
	freopen("test.txt","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		//scanf("%s",str);
		memset(s,' ',sizeof(s));
		memset(str,' ',sizeof(str));
		gets(str);
		puts(str);
		// return 0;
		int len=strlen(str);
		// for(int i=0;str[i]!='\0';i++){
		// 	int a=i/n;
		// 	int b=i%n;
		// 	s[b][a]=str[i];
		// }
		// int a=(len-1)/n;
		// if((len-1)%n!=0)
		// 	a++;
		// // puts(str);
		// // printf("%d\n",len);
		// // printf("%d\n",a);
		// for(int i=0;i<n;i++){
		// 	// for(int j=0;j<=a;j++){
		// 	// 	printf("%c",s[i][j]);
		// 	// }
		// 	for(int j=a-1;j>=0;j--){
		// 		printf("%c",s[i][j]);
		// 	}
		// 	printf("\n");
		// }
		puts(str);
		int a=len/n;
		if(len%n!=0)
			a++;
		for(int i=0;i<a;i++){
			int j=0;
			int num=0;
			while(num<a){
				tm[num]=str[i+j]=='\0'?' ':str[i+j];
				num++;
				j+=a;
			}
			num--;
			while(num){
				printf("%c",tm[num]);
			}
			printf("\n");
		}	
	}
	return 0;
}