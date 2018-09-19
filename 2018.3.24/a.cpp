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
const int maxn=1e5+5;
using namespace std;
char st[300];
char tmp[105];
int p[300];
// void manacher(){
// 	int i;
// 	int mx=0;
// 	int id;
// 	for(int i=1;st[i]!='\0';i++){
// 		if(mx>i){
// 			p[i]=min(p[2*id-i],mx-i);
// 		}
// 		else{
// 			p[i]=1;
// 		}
// 		while(st[i+p[i]]==st[i-p[i]]){
// 			p[i]++;
// 		}
// 		if(p[i]+i>mx){
// 			mx=p[i]+i;
// 			id=i;
// 		}
// 	}
// }
int Next[105];
void getnext(){
	int len=strlen(tmp);
	Next[0]=-1;
	int k=-1;
	int j=0;
	int ans=0;
	while(j<len){
		if(k==-1||tmp[j]==tmp[k]){
			++j;
			++k;
			Next[j]=k;
			if(2*Next[j]>=j)
				ans=max(ans,Next[j]);
		}
		else k=Next[k];
	}
	for(int i=0;i<=len;i++){
		printf("%d ",Next[i]);
	}
	printf("\n");
	printf("%d\n",ans);
	if(ans>len/2)
		ans=len/2;
	printf("%d\n",ans==0?len:len-ans+1);
}
int main(){
	freopen("test.txt","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		int i=0;
		st[i]='#';
		scanf("%s",tmp);
		printf("%s\n",tmp);
		// for(int j=0;tmp[j]!='\0';j++){
		// 	i++;
		// 	st[i]=tmp[j];
		// 	i++;
		// 	st[i]='#';
		// }
		// for(int i=0;st[i]!='\0';i++){
		// 	printf("%c ",st[i]);
		// }
		// printf("\n");
		// manacher();
		// for(int i=0;st[i]!='\0';i++){
		// 	printf("%d ",p[i]);
		// }
		// printf("\n");
		getnext();
	}
	return 0;
}