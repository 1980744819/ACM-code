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
const int maxn=200005;
int ti[maxn];
int op[maxn];
int main(){
	freopen("test.txt","r",stdin);
	int n;
	queue<int>que;
	while(~scanf("%d",&n)){
		char ch;
		int num;
		for(int i=0;i<2*n;i++){
			scanf("%c %d",&ch,&ti[i]);
			if(ch=='+'){
				que.push(i);
				op[i]=0;
			}
			esle{
				op[i]=1;
			}
		}
	}
    return 0;
}
