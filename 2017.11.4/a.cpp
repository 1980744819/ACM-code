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
const int maxn=10000;
int a[11],b[11];
int un[22],in[22];
int main(){
	freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int m,n;
		scanf("%d %d",&m,&n);
		for(int i=0;i<m;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<=n;i++){
			scanf("%d",&b[i]);
		}
		set<int>s1(a,a+m);
		set<int>s2(b,b+n);
		int *end=set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),un);
		int *first=un;
		while(first<end){
			cout<<*first++;
		}
		cout<<endl;
		end=set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),un);
		first=un;
		while(first<end){
			cout<<*first++;
		}
		cout<<endl;

	}
    return 0;
}
