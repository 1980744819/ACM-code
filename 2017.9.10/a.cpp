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
ll fi[10000];
set<ll>st;
void dfs(int cur,int pos,ll ans){
	if(cur==0){
		st.insert(ans);
		return;
	}
	else if(pos<0){
		st.insert(ans);
		return;
	}
	else{
		// for(int i=0;i<=pos;i++){
		// 	dfs(cur-1,i,ans+fi[i]);
		// }
		dfs(cur,pos-1,ans);
		dfs(cur-1,pos,ans+fi[pos]);
	}
}
int main(){
	freopen("test.txt","r",stdin);
	fi[0]=0;
	fi[1]=1;
	st.insert(0);
	st.insert(1);
	for(int i=2;i<80;i++){
		fi[i]=fi[i-1]+fi[i-2];
		st.insert(fi[i]);
		cout<<fi[i]<<endl;
	}
	set<ll>::iterator it=st.begin();
	for(it=st.begin();it!=st.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	
	for(int k=1;k<=3;k++){
		for(int i=0;i<=30;i++){
			dfs(1,i,fi[i]);
		}
		for(it=st.begin();it!=st.end();it++){
			cout<<*it<<" ";
		}
		cout<<endl<<endl;	
	}
	// for(int k=1;k<=10;k++){
	// 	for(int i=0;i<=80;i++){
	// 		dfs(k,i,0);
	// 	}
	// 	set<ll>::iterator it=st.begin();
	// 	for(;it!=st.end();it++){
	// 		cout<<*it<<" ";
	// 	}
	// 	cout<<endl;
	// 	// for(int i=0;i<100000000;i++){
	// 	// 	if()
	// 	// }
	//}
	return 0;
}