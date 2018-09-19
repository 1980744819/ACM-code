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
string s[50005];
bool cmp(string a,string b){
	return a+b<b+a;
}
int main(){
	int n;
	int i,j;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n,cmp);
	for(i=0;i<n;i++){
		cout<<s[i];
	}
	cout<<endl;
    return 0;
}
