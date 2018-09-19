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
const int maxn=1e5+5;
string 	s[maxn];
int Next[maxn];
void getNext(int num,int &j,int &k,int len){
	while(j<len-1){
		if(k==-1||s[num][j]==s[num][k]){
			++k;
			++j;
			Next[j]=k;
		}
		else{
			k=Next[k];
		}
	}
}
int kmp_search(int x,int j,int lenx,int y,int i,int leny){
	while(i<leny&&j<lenx){
		if(j==-1||s[y][i]==s[x][j]){
			i++;
			j++;
		}
		else{
			j=Next[j];
		}
	}
	if(j==lenx)
		return i-j;
	else
		return -1;
}
int search(int x,int y){
	int len=0;
	Next[0]=-1;
	int j=0;
	int k=-1;
	int i=0;
	int maxnlen=0;
	while(len<s[x].size()){
		len++;
		getNext(x,j,k,len);
		i=kmp_search(x,0,len,y,i,s[y].size());
		if(i==-1){
			break;
		}
		else{
			maxnlen=max(maxnlen,len);
		}
	}
	return maxnlen;
}
int main(){
	freopen("test.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i];
			//cout<<s[i]<<endl;
		}
		int m;
		cin>>m;
		int ans=0;
		while(m--){
			int x,y;
			cin>>x>>y;
			if(x>y)
				swap(x,y);
			// ans=max(search(x,y),search(y,x));
			// printf("%d\n",ans);
			ans=0;
			for(int i=1;i<=n;i++){
				if(i!=x&&i!=y){
					int num=min(search(i,x),search(i,y));
					ans=max(num,ans);
				}
			}
			ans=max(ans,search(x,y));
			ans=max(ans,search(y,x));
			printf("%d\n",ans);
		}
	}
	return 0;
}