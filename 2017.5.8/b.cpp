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
char c[100005];
int main(){
	int n,k,a,b;
	int i,j;
	int Min;
	char x='G',y='B';
	scanf("%d %d %d %d",&n,&k,&a,&b);
	if(a<b){
		swap(a,b);
		swap(x,y);
	}
	int num=a/k;
	int u,v;
	int cnt;
	if(a%k!=0)
		num++;
	if(b<num-1){
		printf("NO\n");
	}
	else{
		u=b/num;
		v=b%num;
		cnt=0;
		for(i=1;i<=num;i++){
			if(a>=k){
				for(j=1;j<=k;j++){
					printf("%c",x);
				}
				a-=k;
			}
			else{
				for(j=1;j<=a;j++){
					printf("%c",x);
				}
				a=0;
			}
			for(j=1;j<=u;j++){
				printf("%c",y);
			}
			if(cnt<v){
				printf("%c",y);
				cnt++;
			}
		}
		printf("\n");
	}
    return 0;
}
