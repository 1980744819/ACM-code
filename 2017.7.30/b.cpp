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
const int inf=99999999;
bool usedm[maxn],usedh[maxn];
int w[maxn][maxn];
int line[maxn];
int cntm,cnth;
char mp[maxn][maxn];
int manx[maxn],many[maxn],houx[maxn],houy[maxn];
int cm[maxn],ch[maxn];
bool find(int x){
	usedm[x]=true;
	for(int i=0;i<cnth;i++){
		if(usedh[i]==false&&(cm[x]+ch[i]==w[x][i])){
			usedh[i]=true;
			if(line[i]==-1||find(line[i])){
				line[i]=x;
				return true;
			}
		}
	}
	return false;
}
int km(){
	for(int i=0;i<cntm;i++){
		while(true){
			int d=inf;
			memset(usedm,false,sizeof(usedm));
			memset(usedh,false,sizeof(usedh));
			if(find(i)) break;
			for(int j=0;j<cntm;j++){
				if(usedm[j]){
					for(int k=0;k<cnth;k++){
						if(usedh[k]==false){
							d=min(d,cm[j]+ch[k]-w[j][k]);
						}
					}
				}
			}
			if(d==inf)
				return -1;
			for(int j=0;j<cntm;j++){
				if(usedm[j]){
					cm[j]-=d;
				}
			}
			for(int j=0;j<cnth;j++){
				if(usedh[j]){
					ch[j]+=d;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<cnth	;i++){
		ans+=w[line[i]][i];
		//printf("%d %d %d\n",i,line[i],ans);
	}
	return ans;
}
int main(){
	freopen("test.txt","r",stdin);
	int n,m;
	int i,j;
	while(~scanf("%d %d",&n,&m)&&n&&m){
		for(i=0;i<n;i++){
			scanf("%s",mp[i]);
			//puts(mp[i]);
		}
		cntm=0;
		cnth=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(mp[i][j]=='m'){
					manx[cntm]=i;
					many[cntm]=j;
					cntm++;
					//printf("cntm=%d x=%d y=%d\n",cntm,i,j);
				}
				else if(mp[i][j]=='H'){
					houx[cnth]=i;
					houy[cnth]=j;
					cnth++;
					//printf("cnth=%d x=%d y=%d\n",cnth,i,j);
				}
			}
		}
		//printf("\n");
		memset(cm,0,sizeof(cm));
		memset(ch,0,sizeof(ch));
		for(i=0;i<cntm;i++){
			int d=0-inf;
			for(j=0;j<cnth;j++){
				w[i][j]=abs(manx[i]-houx[j])+abs(many[i]-houy[j]);
				w[i][j]=0-w[i][j];
				//printf("%d %d %d\n",i,j,w[i][j]);
				d=max(w[i][j],d);
			}
			cm[i]=d;
			//printf("%d %d\n",i,d);
		}
		memset(line,-1,sizeof(line));
		printf("%d\n",0-km());
	}
	return 0;
}