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
char str[2005];
char tmp[2005][1005];
int main(){
	freopen("test.txt","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		// printf("%d\n",n);
		gets(str);
		// puts(str);
		int len=strlen(str);
		// printf("%d\n",len);
		int a=len/n;
		if(len%n!=0)
			a++;
		// printf("%d\n",a);
		// len=a*n; 
		// for(int i=len-n;i<=len-1;i++){
		// 	int j=i;
		// 	while(j>=0){
		// 		printf("%c",str[j]);
		// 		j-=n;
		// 	}
		// 	printf("\n");
		// }
		// for(int i=0;i<len;i++){

		// }
		int num=0;
		for(int j=0;j<a;j++){
			for(int i=0;i<n;i++){
				tmp[i][j]=str[num];
				num++;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=a-1;j>=0;j--){
				printf("%c",tmp[i][j]=='\0'?' ':tmp[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}