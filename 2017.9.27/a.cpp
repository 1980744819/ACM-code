
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
const int maxn=1005;
int a[maxn],b[maxn],c[maxn];
char s[maxn];
int get_min(int len){
	int Mi=100;
	for(int i=1;i<=len;i++){
		Mi=min(Mi,a[i]);
	}
	return Mi;
}
int main(){
	freopen("test.txt","w",stdout);
	printf("100\n");
	int num=rand()%10;
	printf("%d",num==0?1:num);
	for(int i=1;i<=1000;i++){
		printf("%d",rand()%10);
	}
	printf("\n");
    return 0;
}
