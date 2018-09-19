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
long long v[4005],d[4005],p[4005];
long long a[4005];
bool book[4005];
long long n;
void jud(int i){
	for(;i<n;i++){
		if(p[i]<0&&book[i]==false){
			book[i]=true;
			int j=i+1;
			int tmp=d[i];
			while(j<n){
				p[j]-=tmp;
				j++;
			}
			jud(i+1);
		}
	}
}
int main(){
	long long i,j;
	long long num;
	long long tmp;
	long long ans=0;
	long long l;
	while(~scanf("%lld",&n)){
		for(i=0;i<n;i++){
			scanf("%lld %lld %lld",&v[i],&d[i],&p[i]);
		}
		i=0;
		ans=0;
		l=0;
		jud(0);
		while(i<n){
			if(book[i]==false){
				if(p[i]>=0){
					tmp=v[i];
					j=i+1;
					ans++;
					a[l]=i;
					l++;
					while(j<n&&tmp>0){
						if(book[j]==false){
							p[j]-=tmp;
							tmp--;
						}
						j++;
					}
					jud(i+1);
				}
				else{
					jud(i);
				}
			}
			i++;
		}
		printf("%lld\n",ans);
		for(i=0;i<l;i++){
			printf("%lld ",a[i]+1);
		}
		printf("\n");
	}
    return 0;
}
