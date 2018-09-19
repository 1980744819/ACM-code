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
const int maxn=1006;
int p[maxn];
bool book[maxn];
int inf=99999999;

int main(){
	freopen("test.txt","r",stdin);
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		memset(p,0,sizeof(p));
		memset(book,false,sizeof(book));
		for(int i=0;i<n;i++){
			scanf("%d",&p[i]);
		}
		int q;
		scanf("%d",&q);
		for(int i=0;i<n;i++){
			int num;
			scanf("%d",&num);
			book[num]=true;
		}
		int left=0;
		while(book[left]==false){
			left++;
		}
		int right=left;
		while(right<n&&right-left+1<=m){
			priority_queue<int>que;
			while(!que.empty()){
				que.pop();
			}
			num=0;
			while(right-left-num+1<m&&right<n){
				right++;
				if(book[right]){
					num++;
				}
			}
			if(left-left-num+1==m){
				for(int i=left;i<=right;i++){
					if(book[i]!=true){
						que.push(p[i]);
					}
				}
			}
			left++;
		}
	}
    return 0;
}
