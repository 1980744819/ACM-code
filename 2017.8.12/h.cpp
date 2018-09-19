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
const int maxn=105;
int a[maxn],l[maxn];
bool book[maxn];
int main(){
	freopen("test.txt","r",stdin);
	int n,m;
	bool flag;
	while(~scanf("%d %d",&n,&m)){
		for(int i=1;i<=m;i++)
			scanf("%d",&l[i]);
		memset(a,-1,sizeof(a));
		memset(book,false,sizeof(book));
		flag=false;
		for(int i=1;i<m;i++){
			int num=l[i+1]-l[i];
			if(num<=0){
				num%=n;
				num+=n;
			}
			if(a[l[i]]==-1){
				if(book[num]==true){
					flag=true;
					printf("-1\n");
					break;
				}
				else{
					a[l[i]]=num;
					book[num]=true;
				}
			}
			else{
				if(a[l[i]]!=num){
					flag=true;
					printf("-1\n");
					break;
				}
			}
		}
		if(flag)
			continue;
		for(int i=1;i<=n;i++){
			if(a[i]==-1){
				for(int j=1;j<=n;j++){
					if(book[j]==false){
						book[j]=true;
						a[i]=j;
						break;
					}
				}
			}
		}
		if(!flag){
			for(int i=1;i<=n;i++)
				printf("%d ",a[i]);
			printf("\n");
		}
	}
	return 0;
}