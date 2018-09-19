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
string a[1005],b[1005];
int main(){
	set<string>st;
	//set<string>::intreator it;
	int n,m;
	int i,j;
	int p1,p2;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<m;i++){
		cin>>b[i];
	}
	p1=0;p2=0;
	//it=st.begin();
	int t=0;
	int con=0;
	while(p1<n){
		if(st.find(a[p1])==st.end()){
			st.insert(a[p1]);
		}
		else{
			//printf("p1 %d\n",p1);
			con++;
		}
		p1++;			
		//con++;
	}		
	while(p2<m){
		if(st.find(b[p2])==st.end()){
			st.insert(b[p2]);
		}
		else{
			//printf("p2 %d\n",p2);
			con++;
		}
		p2++;
		//con++;
	}
	//printf("%d\n",con);
	if(con%2==0){
		if(n>m)
			printf("YES\n");
		else
			printf("NO\n");
	}
	else{
		if(n>m-1)
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;
}
