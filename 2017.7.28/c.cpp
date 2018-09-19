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
using namespace std;
const int maxn=105;
int n,m;
int cnth,cntm;
char mp[maxn][maxn];
bool usedm[maxn],usedh[maxn];
int w[maxn][maxn];
int line[maxn];
int hx[maxn],hy[maxn],mx[maxn],my[maxn];
int cx[maxn],cy[maxn];
bool found(int x){
	usedm[x]=true;
	for(int i=0;i<cnth;i++){
		if(usedh[i]==false&&cx[x]+cy[i]==w[x][i]){
			usedh[i]=true;
			if(line[i]==-1||found(line[i])){
				line[i]=x;
				return true;
			}
		}
	}
	return false;
}
int km(){
	int ans;
	for(int i=0;i<cntm;i++){
		while(true){
			int d=-99999999;
			memset(usedh,false,sizeof(usedh));
			memset(usedm,false,sizeof(usedm));
			if(found(i))break;
			for(int j=0;j<cntm;j++){
				if(usedm[j]){
					for(int k=0;k<cnth;k++){
						if(usedh[k]==false){
							d=max(w[j][j]-cx[j]-cy[j],d);
						}
					}
				}
			}
			if(d==-99999999){
				return -1;
			}
			for(int j=0;j<cntm;j++){
				cx[j]-=d;
			}
			for(int j=0;j<cnth;j++){
				cy[j]+=d;
			}
		}
	}
	ans=0;
	for(int i=0;i<cnth;i++){
		ans+=w[line[i]][i];
	}
	return ans;
}
int main(){
	freopen("test.txt","r",stdin);
	int i,j;
	while(~scanf("%d %d",&n,&m)&&m&&n){
		cnth=0;
		cntm=0;
		for(i=0;i<n;i++){
			scanf("%s",mp[i]);
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				printf("%c",mp[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(mp[i][j]=='H'){
					//printf("H: %d %d\n",i,j);
					hx[cnth]=i;
					hy[cnth]=j;
					cnth++;
				}
				else if(mp[i][j]=='m'){
					//printf("m: %d %d\n",i,j);
					mx[cntm]=i;
					my[cntm]=j;
					cntm++;
				}
			}
		}
		for(i=0;i<maxn;i++)
			cx[i]=9999999;
		memset(cy,0,sizeof(cy));
		memset(line,-1,sizeof(line));
		for(i=0;i<cntm;i++){
			for(j=0;j<cnth;j++){
				w[i][j]=abs(mx[i]-hx[j])+abs(my[i]-hy[j]);
				cx[i]=min(cx[i],w[i][j]);
				printf("%d ",w[i][j]);
			}
			printf("\n");
		}
		// int ans=km();
		// printf("%d",ans);
	}
	return 0;
}