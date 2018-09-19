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
int s[100];
int a[100];
int len;
int ba;
bool isper(int num){
	len=0;
	while(num){
		int tmp=num%ba;
		s[++len]=tmp;
		num/=ba;
	}
	int i=1;
	int j=len;
	while(i<=j){
		if(s[i]!=s[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}
int main(){
	//freopen("test.txt","r",stdin);
	int num;
	int ans=0;
	int start;
	int a,b;
	while(~scanf("%d %d %d %d",&start,&num,&a,&b)){
		for(ba=a;ba<=b;ba++){
			ans=0;
			for(int i=start;i<=num;i++){
				if(isper(i)){
					ans++;
					//printf("%d %d\n",ans,i);
				}
			}
			printf("%d %d\n",ans,ba);
		}
	}
	return 0;
}