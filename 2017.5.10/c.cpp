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
struct stu{
	string s;
	int len;
}node[50005];
bool cmp(stu u,stu v){
	return u.s<v.s;
}
int main(){
	int i,j;
	int M=0;
	int n;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>node[i].s;
		node[i].len=node[i].s.size();
		if(node[i].len>M)
			M=node[i].len;
	}
	for(i=0;i<n;i++){
		node[i].s.append(M-node[i].len,'z');
	}
	// for(i=0;i<n;i++)
	// 	cout<<node[i].s<<endl;
	sort(node,node+n,cmp);
	for(i=0;i<n;i++){
		for(j=0;j<node[i].len;j++){
			cout<<node[i].s[j];
		}
	}
	cout<<endl;
    return 0;
}
