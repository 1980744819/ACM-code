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
int main(){
	freopen("test.txt","r",stdin);
	int n,a,b;
	int num;
	int ans=0;
	int c;
	while(~scanf("%d %d %d",&n,&a,&b)){
		ans=0;
		c=0;
		for(int i=0;i<n;i++){
			scanf("%d",&num);
			if(num==1){
				if(a>0){
					a--;
				}
				else{
					if(b>0){
						b--;
						c++;
					}
					else{
						if(c>0){
							c--;
						}
						else{
							ans++;
						}
					}
				}
			}
			else{
				if(b>0){
					b--;
				}
				else{
					ans+=2;
				}
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}
