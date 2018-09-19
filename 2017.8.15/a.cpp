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
const int maxn=1e7+5;
int a[maxn];
void init(){
	int i,j;
	a[1]=1;
	a[2]=2;
	a[3]=2;
	i=3;
	j=3;
	int num=1;
	while(j<maxn){
		for(int k=1;k<=a[i]&&j+k<maxn;k++){
			a[j+k]=num;
		}
		j+=a[i];
		if(num==1)
			num=2;
		else
			num=1;
		i++;
	}
	//printf("%d",a[10000000]);
}
int main(){
	//freopen("test.txt","r",stdin);
	int t;
	init();
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}