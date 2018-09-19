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
int x[300005];
int re[300005];
int c[300005];
int main(){
	vector<int>v;
	int n,q;
	int i,j;
	scanf("%d %d",&n,&q);
	int type,xi,ti;
	int start;
	int coun=0;
	while(q--){
		scanf("%d",&type);
		if(type==1){
			scanf("%d",&xi);
			x[xi]++;
			coun++;
			v.push_back(xi);
			printf("%d\n",coun);
		}
		else if(type==2){
			scanf("%d",&xi);
			coun-=x[xi];
			re[xi]=x[xi];
			//x[xi]=0;
			printf("%d\n",coun);
		}
		else{
			scanf("%d",&ti);
			for(i=0;i<ti;i++){
				if(c[v[i]]<re[v[i]]){
					c[v[i]]++;
				}
				else{
					re[v[i]]++;
					c[v[i]]++;
					coun--;
				}
			}
			printf("%d\n",coun);
			memset(c,0,sizeof(c));
		}
	}
    return 0;
}
