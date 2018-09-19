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
struct stu{
	string st;
	int step;
};
int main(){
	//freopen("test.txt","r",stdin);
	int i,j;
	int t;
	int n;
	string a,b,c;
	struct stu tm,tmp;
	cin>>t;
	int coun=0;
	map<string,int>mp;
	queue<struct stu>que;
	while(t--){
		coun++;
		cin>>n>>a>>b>>c;
		cout<<coun<<" ";
		//cout<<a<<endl<<b<<endl<<c<<endl;
		while(!que.empty()){
			que.pop();
		}
		mp.clear();
		tmp.st.clear();
		for(i=0;i<n;i++){
			tmp.st.append(b,i,1);
			tmp.st.append(a,i,1);
		}
		tmp.step=1;
		que.push(tmp);
		//cout<<tmp.st<<endl;
		mp[tm.st]=1;
		while(!que.empty()){
			tm=que.front();
			//cout<<tm.st<<" ";
			if(tm.st==c){
				cout<<tm.step<<endl;
				break;
			}
			tmp.step=tm.step+1;
			// for(i=0;i<n;i++){
			// 	a[i]=tm.st[i];
			// 	b[i]=tm.st[i+n];
			// }
			a.replace(a.begin(),a.end(),tm.st.begin(),tm.st.begin()+n);
			b.replace(b.begin(),b.end(),tm.st.begin()+n,tm.st.end());
			//cout<<a<<" "<<b<<endl;
			tmp.st.clear();
			for(i=0;i<n;i++){
				tmp.st.append(b,i,1);
				tmp.st.append(a,i,1);
			}
			//cout<<tmp.st<<endl;
			if(mp[tmp.st]==1){
				cout<<"-1"<<endl;
				break;
			}
			else{
				que.push(tmp);
				mp[tmp.st]=1;
			}
			que.pop();
		}
	}
	return 0;
}